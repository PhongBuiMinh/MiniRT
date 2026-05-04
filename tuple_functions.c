/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/04 19:46:55 by bpetrovi         ###   ########.fr       */
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
	printf("w: %f,\n", tuple->w);
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

int	main(void)
{
	t_tuple	*a;
	//t_tuple	*b;
	//float	magn;

	a = vector(1, 2, 3);
	//b = point(1, 2, 3);
	print_tuple(a);
	//print_tuple(b);
	//magn = magnitude(a);
	normalize(a);
	print_tuple(a);
	return (0);
}
