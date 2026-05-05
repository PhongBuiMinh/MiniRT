/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/05 20:03:33 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*vector(float x, float y, float z)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(tuple));
	if (!tuple)
		return (NULL);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = VECTOR;
	return (tuple);
}

t_tuple	*point(float x, float y, float z)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(tuple));
	if (!tuple)
		return (NULL);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = POINT;
	return (tuple);
}

t_tuple	*add(t_tuple *tuple_a, t_tuple *tuple_b)
{
	t_tuple	*new_tuple;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	new_tuple->x = tuple_a->x + tuple_b->x;
	new_tuple->y = tuple_a->y + tuple_b->y;
	new_tuple->z = tuple_a->z + tuple_b->z;
	new_tuple->w = tuple_a->w + tuple_b->w;
	return (new_tuple);
}

t_tuple	*substract(t_tuple *tuple_a, t_tuple *tuple_b)
{
	t_tuple	*new_tuple;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	new_tuple->x = tuple_a->x - tuple_b->x;
	new_tuple->y = tuple_a->y - tuple_b->y;
	new_tuple->z = tuple_a->z - tuple_b->z;
	new_tuple->w = tuple_a->w - tuple_b->w;
	return (new_tuple);
}

float	magnitude(t_tuple	*tuple)
{
	float	magnitude;

	magnitude = 0;
	magnitude += tuple->x * tuple->x;
	magnitude += tuple->y * tuple->y;
	magnitude += tuple->z * tuple->z;
	magnitude += tuple->w * tuple->w;
	return (sqrtf(magnitude));
}

float	dot(t_tuple *a, t_tuple *b)
{
	return (a->x + b->x * a->y + b->y
		* a->z + b->z * a->w + b->w);
}

t_tuple	*cross(t_tuple *a, t_tuple *b)
{
	return (vector(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z,
			a->x * b->y - a->y * b->x));
}

void	negate(t_tuple *tuple)
{
	tuple->x = -tuple->x;
	tuple->y = -tuple->y;
	tuple->z = -tuple->z;
	tuple->w = -tuple->w;
}

void	multiply(t_tuple *tuple, float scalar)
{
	tuple->x = tuple->x * scalar;
	tuple->y = tuple->y * scalar;
	tuple->z = tuple->z * scalar;
	tuple->w = tuple->w * scalar;
}

void	divide(t_tuple *tuple, float divider)
{
	tuple->x = tuple->x / divider;
	tuple->y = tuple->y / divider;
	tuple->z = tuple->z / divider;
	tuple->w = tuple->w / divider;
}

void	normalize(t_tuple *tuple)
{
	divide(tuple, magnitude(tuple));
}


void	print_tuple(t_tuple *tuple)
{
	printf("x: %f, ", tuple->x);
	printf("y: %f, ", tuple->y);
	printf("z: %f, ", tuple->z);
	printf("w: %f\n", tuple->w);
}

void	check_tuple(t_tuple *tuple)
{
	if (tuple->w == VECTOR)
		printf("Tuple is a vector\n");
	else if (tuple->w == POINT)
		printf("Tuple is a point\n");
	else
		printf("Tuple is neither\n");
}

bool	equal(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

t_projectile *init_projectile(t_tuple *position, t_tuple *velocity)
{
	t_projectile	*projectile;

	projectile = malloc(sizeof(t_projectile));
	if (!projectile)
		return (NULL);
	projectile->position = position;
	//normalize(velocity);
	projectile->velocity = velocity;
	return (projectile);
}

t_environment *init_environment(t_tuple *gravity, t_tuple *wind)
{
	t_environment	*environment;

	environment = malloc(sizeof(t_environment));
	if (!environment)
		return (NULL);
	environment->gravity = gravity;
	environment->wind = wind;
	return (environment);
}

void	deconstruct_projectile(t_projectile *projectile)
{
	if (!projectile)
		return ;
	free(projectile->position);
	free(projectile->velocity);
	free(projectile);
}

void	deconstruct_environment(t_environment *environment)
{
	if (!environment)
		return ;
	free(environment->gravity);
	free(environment->wind);
	free(environment);
}

void	tick(t_environment *environment, t_projectile *projectile)
{
	projectile->position = add(projectile->position, projectile->velocity);
	projectile->velocity = add(projectile->velocity, add(environment->gravity, environment->wind));
}

int	main(void)
{
	int				number_of_ticks;
	t_projectile	*projectile;
	t_environment	*environment;

	projectile = init_projectile(point(0, 1, 0), vector(1, 1, 0));
	environment = init_environment(vector(0, -0.01, 0), vector(-0.01, 0, 0));
	if (!projectile || !environment)
		return (deconstruct_projectile(projectile), deconstruct_environment(environment), 1);
	number_of_ticks = 0;
	while (projectile->position->y > 0)
	{
		tick(environment, projectile);
		number_of_ticks++;
		printf("ticks: %i\n", number_of_ticks);
		print_tuple(projectile->position);
	}
	deconstruct_projectile(projectile);
	deconstruct_environment(environment);
	return (0);
}
