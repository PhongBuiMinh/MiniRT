/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:55:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/01 15:42:19 by bpetrovi         ###   ########.fr       */
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

t_tuple	position(t_ray ray, int time)
{
	return (add(ray.origin, multiply(ray.direction, time)));
}

t_sphere	sphere(int id)
{
	t_sphere	new_sphere;

	new_sphere.id = id;
	return (new_sphere);
}

void	set_transformation(t_sphere *sphere, t_matrix transformation)
{
	sphere->transformation = transformation;
}

t_ray	ray_transform(t_ray ray, t_matrix transformation)
{
	t_ray	transformed_ray;

	transformed_ray.origin = matrix_tuple_multiply(transformation, ray.origin);
	transformed_ray.direction = matrix_tuple_multiply(transformation,
			ray.direction);
	return (transformed_ray);
}


