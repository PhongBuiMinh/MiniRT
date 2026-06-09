/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:58:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:11:35 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	prepare_computations(t_intersection is, t_ray r)
{
	t_comps	computations;
	t_tuple	is_pos;

	is_pos = r_pos(r, is.t);
	computations.sphere = is.object;
	computations.point = is_pos;
	computations.eyev = t_negate(r.direction);
	computations.normalv = normal_at(is.object, is_pos);
	return (computations);
}

t_world	default_world(void)
{
	t_world	new_world;

	new_world.light = point_light(point(-10, 10, -10), color(1, 1, 1));
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

t_intersections	intersect_world(t_ray ray, t_world world)
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
