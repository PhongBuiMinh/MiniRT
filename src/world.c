/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:58:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 21:35:55 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	world_default(void)
{
	t_world	new_world;

	new_world.light = light_init(point(-10, 10, -10), color(1, 1, 1));
	new_world.spheres = malloc(sizeof(t_sphere) * 2);
	if (!new_world.spheres)
		return (new_world.object_cnt = -1, new_world);
	new_world.spheres[0] = sphere(1);
	new_world.spheres[1] = sphere(2);
	new_world.spheres[0].material.color = color(0.8, 1, 0.6);
	new_world.spheres[0].material.diffuse = 0.7;
	new_world.spheres[0].material.specular = 0.2;
	new_world.spheres[1].transformation = scaling(0.5, 0.5, 0.5);
	new_world.object_cnt = 2;
	return (new_world);
}

// FIX ERROR HANDLING

t_intersections	world_intersect(t_world world, t_ray ray)
{
	t_intersections	all;
	t_intersections	xs;
	int				i;

	i = 0;
	all = xs_init();
	if (all.err)
		return (all);
	while (i < world.object_cnt)
	{
		xs = xs_find(world.spheres[i], ray);
		if (xs.err == true)
			return (free(all.intersections), all.err = true, all);
		if (!xs_append(&all, xs))
			return (all.err = true, all);
		xs_sort(&all);
		i++;
	}
	return (all);
}
