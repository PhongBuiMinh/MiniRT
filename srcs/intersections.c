/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:45:35 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/31 17:19:57 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	discriminant(t_ray ray)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;

	sphere_to_ray = substract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	return (b * b - 4 * a * c);
}

t_intersection	intersect(t_sphere sphere, t_ray ray)
{
	t_intersection	xs;
	t_tuple			sphere_to_ray;
	double			d;
	double			a;
	double			b;

	(void)sphere;
	d = discriminant(ray);
	printf("discriminant: %f\n", d);
	if (d < 0)
		return (xs.count = 0, xs);
	xs.count = 2;
	sphere_to_ray = substract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	xs.t1 = (-b - sqrt(d)) / (2 * a);
	xs.t2 = (-b + sqrt(d)) / (2 * a);
	return (xs);
}
