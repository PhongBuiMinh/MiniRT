/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:55:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/08 14:55:06 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_tuple	position(t_ray ray, float time)
{
	return (add(ray.origin, scalar(ray.direction, time)));
}

t_sphere	sphere(int id)
{
	t_sphere	new_sphere;

	new_sphere.id = id;
	new_sphere.transformation = init_ind_matrix(4, 4);
	new_sphere.material = material();
	return (new_sphere);
}

void	set_transformation(t_sphere *sphere, t_matrix transformation)
{
	sphere->transformation = transformation;
}

t_ray	ray_transform(t_ray ray, t_matrix transformation)
{
	t_ray	transformed_ray;

	transformed_ray.origin = mat_apply(transformation, ray.origin);
	transformed_ray.direction = mat_apply(transformation,
			ray.direction);
	return (transformed_ray);
}


