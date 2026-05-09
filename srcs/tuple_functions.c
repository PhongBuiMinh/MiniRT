/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/09 17:29:19 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_tuple	vector(float x, float y, float z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = VECTOR;
	return (tuple);
}

t_tuple	point(float x, float y, float z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = POINT;
	return (tuple);
}

t_tuple	add(t_tuple tuple_a, t_tuple tuple_b)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple_a.x + tuple_b.x;
	new_tuple.y = tuple_a.y + tuple_b.y;
	new_tuple.z = tuple_a.z + tuple_b.z;
	new_tuple.w = tuple_a.w + tuple_b.w;
	return (new_tuple);
}

t_tuple	substract(t_tuple tuple_a, t_tuple tuple_b)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple_a.x - tuple_b.x;
	new_tuple.y = tuple_a.y - tuple_b.y;
	new_tuple.z = tuple_a.z - tuple_b.z;
	new_tuple.w = tuple_a.w - tuple_b.w;
	return (new_tuple);
}

float	magnitude(t_tuple	tuple)
{
	float	magnitude;

	magnitude = 0;
	magnitude += tuple.x * tuple.x;
	magnitude += tuple.y * tuple.y;
	magnitude += tuple.z * tuple.z;
	magnitude += tuple.w * tuple.w;
	return (sqrtf(magnitude));
}

float	dot(t_tuple a, t_tuple b)
{
	return (a.x + b.x * a.y + b.y
		* a.z + b.z * a.w + b.w);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	return (vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}

t_tuple	multiply_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x * b.x;
	new_tuple.y = a.y * b.y;
	new_tuple.z = a.z * b.z;
	new_tuple.w = a.w * b.w;
	return (new_tuple);
}

t_tuple	negate(t_tuple tuple)
{
	tuple.x = -tuple.x;
	tuple.y = -tuple.y;
	tuple.z = -tuple.z;
	tuple.w = -tuple.w;
	return (tuple);
}

t_tuple	multiply(t_tuple tuple, float scalar)
{
	tuple.x = tuple.x * scalar;
	tuple.y = tuple.y * scalar;
	tuple.z = tuple.z * scalar;
	tuple.w = tuple.w * scalar;
	return (tuple);
}

t_tuple	divide(t_tuple tuple, float divider)
{
	tuple.x = tuple.x / divider;
	tuple.y = tuple.y / divider;
	tuple.z = tuple.z / divider;
	tuple.w = tuple.w / divider;
	return (tuple);
}

t_tuple	normalize(t_tuple tuple)
{
	return (divide(tuple, magnitude(tuple)));
}


void	print_tuple(t_tuple tuple)
{
	printf("x: %f, ", tuple.x);
	printf("y: %f, ", tuple.y);
	printf("z: %f, ", tuple.z);
	printf("w: %f\n", tuple.w);
}

void	check_tuple(t_tuple tuple)
{
	if (tuple.w == VECTOR)
		printf("Tuple is a vector\n");
	else if (tuple.w == POINT)
		printf("Tuple is a point\n");
	else
		printf("Tuple is neither\n");
}

//PROJECTILE FIRING DIAGONALLY UPWARDS
//int	main(void)
//{
//	t_projectile	projectile;
//	t_environment	environment;
//	t_canvas		canvas;
//	int				x;
//	int				y;

//	init_canvas(&canvas, 1000, 500);
//	projectile = init_projectile(point(0, 1, 0), multiply(normalize(vector(1, 1.8, 0)), 11.25));
//	environment = init_environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));
//	while (projectile.position.y > 0)
//	{
//		//printf("%f\n %f\n", projectile.position.y, projectile.position.x);
//		tick(&environment, &projectile);
//		x = (int)(projectile.position.x + 0.5);
//		y = (int)(projectile.position.y + 0.5);
//		y = canvas.height - y;
//		write_pixel(&canvas, x, y, color(1, 0, 0));
//	}
//	canvas_to_ppm(&canvas);
//	free_pixels(canvas.pixels);
//	return (0);
//}
