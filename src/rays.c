/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:55:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:42:37 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_tuple	position(t_ray ray, float time)
{
	return (t_add(ray.origin, t_scale(ray.direction, time)));
}

t_ray	ray_transform(t_ray ray, t_matrix transformation)
{
	t_ray	transformed_ray;

	transformed_ray.origin = mat_apply(transformation, ray.origin);
	transformed_ray.direction = mat_apply(transformation,
			ray.direction);
	return (transformed_ray);
}


