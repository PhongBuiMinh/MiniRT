/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:58:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 22:25:00 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_world	world_default(void)
{
	t_world	new_world;

	new_world.light = light_init(point(-10, 10, -10), color(1, 1, 1));
	new_world.spheres = malloc(sizeof(t_sphere) * 2);
	if (!new_world.spheres)
		return (new_world.obj_c = -1, new_world);
	new_world.spheres[0] = sphere(1);
	new_world.spheres[1] = sphere(2);
	new_world.spheres[0].material.diffuse = 0.7;
	new_world.spheres[0].material.specular = 0.2;
	new_world.spheres[1].transformation = scaling(0.5, 0.5, 0.5);
	new_world.obj_c = 2;
	return (new_world);
}

t_intersections	world_intersect(t_ray ray, t_world world)
{
	t_intersections	all;
	t_intersections	xs;
	int				i;

	i = 0;
	all = xs_init();
	if (all.err)
		return (all);
	while (i < world.obj_c)
	{
		xs = xs_find(world.spheres[i], ray);
		if (xs.err == true)
			return (free(all.intersections), all.err = true, all);
		if (!xs_append(&all, xs))
			return (free(all.intersections), all.err = true, all);
		xs_sort(&all);
		i++;
	}
	return (all);
}
