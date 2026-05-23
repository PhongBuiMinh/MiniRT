/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 20:41:52 by fbui-min          #+#    #+#             */
/*   Updated: 2026/05/23 19:04:53 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./transform.h"

t_matrix4	translation(double x, double y, double z)
{
	return (matrix4_rows(
		tuple(1, 0, 0, x),
		tuple(0, 1, 0, y),
		tuple(0, 0, 1, z),
		tuple(0, 0, 0, 1)));
}

t_matrix4	scaling(double x, double y, double z)
{
	return (matrix4_rows(
		tuple(x, 0, 0, 0),
		tuple(0, y, 0, 0),
		tuple(0, 0, z, 0),
		tuple(0, 0, 0, 1)));
}

t_matrix4	rotation_x(double radians)
{
	double	c;
	double	s;

	c = cos(radians);
	s = sin(radians);
	return (matrix4_rows(
		tuple(1, 0, 0, 0),
		tuple(0, c, -s, 0),
		tuple(0, s,  c, 0),
		tuple(0, 0, 0, 1)));
}

t_matrix4	rotation_y(double radians)
{
	double	c;
	double	s;

	c = cos(radians);
	s = sin(radians);
	return (matrix4_rows(
		tuple( c, 0,  s, 0),
		tuple( 0, 1,  0, 0),
		tuple(-s, 0,  c, 0),
		tuple( 0, 0,  0, 1)));
}

t_matrix4	rotation_z(double radians)
{
	double	c;
	double	s;

	c = cos(radians);
	s = sin(radians);
	return (matrix4_rows(
		tuple( c, -s, 0, 0),
		tuple( s,  c, 0, 0),
		tuple( 0,  0, 1, 0),
		tuple( 0,  0, 0, 1)));
}

t_matrix4	shearing(double xy, double xz,
				double yx, double yz,
				double zx, double zy)
{
	return (matrix4_rows(
		tuple(1,  xy, xz, 0),
		tuple(yx, 1,  yz, 0),
		tuple(zx, zy, 1,  0),
		tuple(0,  0,  0,  1)));
}

t_tuple	transform_point(t_matrix4 t, t_tuple p)
{
	return (matrix4_mul_tuple(t, p));
}

t_tuple	transform_vector(t_matrix4 t, t_tuple v)
{
	return (matrix4_mul_tuple(t, v));
}
