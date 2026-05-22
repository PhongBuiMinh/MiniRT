/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:12:01 by fbui-min          #+#    #+#             */
/*   Updated: 2026/05/22 18:55:10 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	point(double x, double y, double z)
{
	return (tuple(x, y, z, 1.0));
}

t_tuple	vector(double x, double y, double z)
{
	return (tuple(x, y, z, 0.0));
}

int	double_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

int	tuple_equal(t_tuple a, t_tuple b)
{
	return (double_equal(a.x, b.x)
		&& double_equal(a.y, b.y)
		&& double_equal(a.z, b.z)
		&& double_equal(a.w, b.w));
}

int	is_point(t_tuple a)
{
	return (double_equal(a.w, 1.0));
}

int is_vector(t_tuple a)
{
	return (double_equal(a.w, 0.0));
}

t_tuple	add_tuple(t_tuple a, t_tuple b)
{
	return (tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_tuple	sub_tuple(t_tuple a, t_tuple b)
{
	return (tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

t_tuple	negate_tuple(t_tuple a)
{
	return (tuple(-a.x, -a.y, -a.z, -a.w));
}

t_tuple	mul_tuple_scalar(t_tuple a, double s)
{
	return (tuple(a.x * s, a.y * s, a.z * s, a.w * s));
}

t_tuple	div_tuple_scalar(t_tuple a, double s)
{
	return (tuple(a.x / s, a.y / s, a.z / s, a.w / s));
}

double	magnitude(t_tuple v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

t_tuple	normalize(t_tuple v)
{
	double	mag;

	mag = magnitude(v);
	return (tuple(v.x / mag, v.y / mag, v.z / mag, v.w / mag));
}

double	dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	return (vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}
