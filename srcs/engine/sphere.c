/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:56:43 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/05 19:58:28 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	sphere_new(void)
{
	t_sphere	s;

	s.transform = matrix4_identity();
	s.inverse = matrix4_identity();
	s.material = material_default();
	return (s);
}

void	sphere_set_transform(t_sphere *s, t_matrix4 t)
{
	if (!s)
		return;
	s->transform = t;
	s->inverse = matrix4_inverse(t);
}

t_tuple	sphere_normal_at(const t_sphere *s, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = matrix4_mul_tuple(s->inverse, world_point);
	object_normal = sub_tuple(object_point, point(0, 0, 0));
	world_normal = matrix4_mul_tuple(matrix4_transpose(s->inverse), object_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}
