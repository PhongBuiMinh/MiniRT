/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:03:11 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:18:44 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// WORLD_P = POINT IN WORLD SPACE, AND LOCAL_P = POINT IN OBJECT SPACE

t_tuple	normal_at(t_object *object, t_tuple world_p)
{
	t_tuple	local_p;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_p = m_apply(inversion(object->transformation), world_p);
	local_normal = object->normal_at(local_p, object);
	world_normal = m_apply(transpose(inversion(object->transformation)),
			local_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

// is_point = intersection point

t_tuple	normal_at_sphere(t_tuple is_point, t_object *object)
{
	(void)object;
	return (t_substract(is_point, point(0, 0, 0)));
}

t_tuple	normal_at_plane(t_tuple is_point, t_object *object)
{
	(void)object;
	(void)is_point;
	return (vector(0, 1, 0));
}

t_tuple	normal_at_cylinder(t_tuple is_point, t_object *object)
{
	t_cylinder	*cylinder;
	double		distance;

	cylinder = (t_cylinder *)object;
	distance = is_point.x * is_point.x + is_point.z * is_point.z;
	if (distance < 1 && is_point.y >= cylinder->max - EPSILON)
		return (vector(0, 1, 0));
	if (distance < 1 && is_point.y <= cylinder->min + EPSILON)
		return (vector(0, -1, 0));
	return (vector(is_point.x, 0, is_point.z));
}
