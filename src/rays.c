/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:55:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:24:27 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	r_init(t_tuple origin, t_tuple direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_tuple	r_pos(t_ray ray, float time)
{
	return (t_add(ray.origin, t_scale(ray.direction, time)));
}

t_ray	r_transform(t_ray ray, t_matrix transformation)
{
	t_ray	transformed_ray;

	transformed_ray.origin = m_apply(transformation, ray.origin);
	transformed_ray.direction = m_apply(transformation,
			ray.direction);
	return (transformed_ray);
}

t_ray	r_find(t_scene *scene, int x, int y)
{
	t_tuple	direction;
	float	world_x;
	float	world_y;

	world_y = scene->half - y * scene->pixel_size;
	world_x = -scene->half + x * scene->pixel_size;
	direction = t_substract(point(world_x, world_y, scene->wall_z),
			scene->origin);
	direction = normalize(direction);
	return (r_init(scene->origin, direction));
}
