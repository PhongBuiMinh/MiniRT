/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:40:19 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:16:00 by bpetrovi         ###   ########.fr       */
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

// WORLD_P = POINT IN WORLD SPACE, AND OBJECT_P = POINT IN OBJECT SPACE
t_tuple	normal_at(t_sphere sphere, t_tuple world_p)
{
	t_tuple		object_p;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	inverse_transpose;

	object_p = m_apply(inversion(sphere.transformation), world_p);
	object_normal = t_substract(object_p, point(0, 0, 0));
	inverse_transpose = transpose(inversion(sphere.transformation));
	world_normal = m_apply(inverse_transpose, object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (t_substract(in,
			t_scale
			(t_scale(normal, 2), dot(in, normal))));
}
