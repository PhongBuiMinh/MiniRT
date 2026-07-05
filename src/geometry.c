/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:40:19 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/03 22:19:09 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_tuple	normalize(t_tuple tuple)
{
	return (t_divide(tuple, magnitude(tuple)));
}

// WORLD_P = POINT IN WORLD SPACE, AND LOCAL_P = POINT IN OBJECT SPACE

t_tuple	normal_at(t_object object, t_tuple world_p)
{
	t_tuple	local_p;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_p = m_apply(inversion(object.transformation), world_p);
	local_normal = object.normal_at(local_p);
	world_normal = m_apply(transpose(inversion(object.transformation)),
			local_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

// is_point = intersection point

t_tuple	normal_at_sphere(t_tuple is_point)
{
	return (t_substract(is_point, point(0, 0, 0)));
}

t_tuple	normal_at_plane(t_tuple	is_point)
{
	(void)is_point;
	return (vector(0, 1, 0));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (t_substract(in,
			t_scale
			(t_scale(normal, 2), dot(in, normal))));
}
