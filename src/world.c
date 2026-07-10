/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:58:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 20:11:55 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	world_default(void)
{
	t_world	new_world;

	new_world.light = light_init(point(-10, 10, -10), color(1, 1, 1));
	new_world.object_cnt = 2;
	int	i = 0;
	while (i < new_world.object_cnt)
	{
		new_world.objects[i] = sphere_create(i);
		i++;
	}
	new_world.objects[0]->material.color = color(0.8, 1, 0.6);
	new_world.objects[0]->material.diffuse = 0.7;
	new_world.objects[0]->material.specular = 0.2;
	new_world.objects[1]->transformation = scaling(0.5, 0.5, 0.5);
	return (new_world);
}

// check

bool	is_shadowed(t_world world, t_tuple point)
{
	t_intersections	xs;
	t_intersection	h;
	t_tuple			v_light;
	double			distance;

	v_light = t_substract(world.light.pos, point);
	distance = magnitude(v_light);
	xs = world_intersect(world, r_init(point, normalize(v_light)));
	if (xs.err)
		return (false);
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
	while (i < world.object_cnt)
	{
		intersect(world.objects[i], ray, &xs);
		if (xs.err == true)
			return (xs);
		i++;
	}
	return (xs);
}
