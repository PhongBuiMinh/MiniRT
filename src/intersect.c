/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:06:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:18:21 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect(t_object *object, t_ray ray, t_intersections *xs)
{
	t_ray			local_ray;

	local_ray = r_transform(ray, inversion(object->transformation));
	object->intersect(object, local_ray, xs);
	xs_sort(xs);
}

void	intersect_plane(t_object *object, t_ray ray, t_intersections *xs)
{
	if (fabs(ray.direction.y) < EPSILON)
		return ;
	xs_push(xs, intersection(-ray.origin.y / ray.direction.y, object));
}

void	intersect_caps(t_object *object, t_ray ray, t_intersections *xs)
{
	t_cylinder	*cylinder;
	double		t;

	cylinder = (t_cylinder *)object;
	if (!cylinder->closed || equal(ray.direction.y, 0))
		return ;
	t = (cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_caps(ray, t))
		if (!xs_push(xs, intersection(t, object)))
			return ;
	t = (cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_caps(ray, t))
		xs_push(xs, intersection(t, object));
}

void	intersect_cylinder(t_object *object, t_ray ray, t_intersections *xs)
{
	double			a;
	double			b;
	double			c;
	double			d;

	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	b = 2 * (ray.origin.x * ray.direction.x
			+ ray.origin.z * ray.direction.z);
	c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	if (!equal(a, 0))
	{
		d = b * b - 4 * a * c;
		if (d >= 0)
		{
			if (!truncate_cylinder(object, ray, xs, (-b - sqrt(d)) / (2 * a)))
				return ;
			truncate_cylinder(object, ray, xs, (-b + sqrt(d)) / (2 * a));
		}
	}
	intersect_caps(object, ray, xs);
}

void	intersect_sphere(t_object *object, t_ray ray, t_intersections *xs)
{
	double			d;
	double			a;
	double			b;
	double			c;
	t_tuple			sphere_to_ray;

	sphere_to_ray = t_substract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	d = b * b - 4 * a * c;
	if (d < 0)
		return ;
	if (!xs_push(xs, intersection((-b - sqrt(d)) / (2 * a), object)))
		return ;
	xs_push(xs, intersection((-b + sqrt(d)) / (2 * a), object));
}
