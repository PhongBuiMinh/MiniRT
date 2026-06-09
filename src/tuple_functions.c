/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:06:05 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	vector(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = VECTOR;
	return (tuple);
}

t_tuple	point(double x, double y, double z)
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

double	magnitude(t_tuple	tuple)
{
	double	magnitude;

	magnitude = 0;
	magnitude += tuple.x * tuple.x;
	magnitude += tuple.y * tuple.y;
	magnitude += tuple.z * tuple.z;
	magnitude += tuple.w * tuple.w;
	return (sqrtf(magnitude));
}

double	dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w);
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

t_tuple	scalar(t_tuple tuple, double scalar)
{
	tuple.x = tuple.x * scalar;
	tuple.y = tuple.y * scalar;
	tuple.z = tuple.z * scalar;
	tuple.w = tuple.w * scalar;
	return (tuple);
}

t_tuple	divide(t_tuple tuple, double divider)
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


//PROJECTILE FIRING DIAGONALLY UPWARDS
//int	main(void)
//{
//	t_projectile	projectile;
//	t_environment	environment;
//	t_canvas		canvas;
//	int				x;
//	int				y;

//	init_canvas(&canvas, 1000, 500);
//	projectile = init_projectile(point(0, 1, 0), scalar(normalize(vector(1, 1.8, 0)), 11.25));
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


// DRAWING A CLOCK
//int	main(void)
//{
//	t_canvas	canvas;
//	t_tuple		p;
//	int			i = 12;

//	init_canvas(&canvas, 1000, 1000);
//	p = point(0, 0, 0);
//	p = mat_apply(translation(0, 300, 0), p);
//	while (i > 0)
//	{
//		//print_tuple(p);
//		write_star(&canvas, p.x + canvas.width / 2, p.y + canvas.height / 2, color(1, 0, 0));
//		p = mat_apply(rotation_z(PI / 6), p);
//		i--;
//	}
//	canvas_to_ppm(&canvas);
//}