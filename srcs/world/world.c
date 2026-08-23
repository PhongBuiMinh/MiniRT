/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:58:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 17:33:07 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_shadowed(t_world world, t_tuple point, bool *error)
{
	t_intersections	xs;
	t_intersection	h;
	t_tuple			v_light;
	double			distance;

	v_light = t_substract(world.light.pos, point);
	distance = magnitude(v_light);
	xs = world_intersect(world, r_init(point, normalize(v_light)));
	if (xs.err)
		return (*error = true, false);
	h = hit(xs);
	free(xs.intersections);
	if (hit_exists(h) && h.t < distance)
		return (true);
	return (false);
}

t_intersections	world_intersect(t_world world, t_ray ray)
{
	t_intersections	xs;
	int				i;

	i = 0;
	xs = xs_init();
	if (xs.err)
		return (xs);
	while (i < world.object_cnt)
	{
		intersect(world.objects[i], ray, &xs);
		if (xs.err == true)
			return (xs);
		i++;
	}
	xs_sort(&xs);
	return (xs);
}
