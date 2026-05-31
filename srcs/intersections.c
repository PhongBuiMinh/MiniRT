/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:45:35 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/31 20:10:48 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_intersections	xs_init(void)
{
	t_intersections	new_xs;

	new_xs.capacity = 4;
	new_xs.count = 0;
	new_xs.intersections = malloc(sizeof(t_intersection) * new_xs.capacity);
	if (new_xs.intersections == NULL)
		return (new_xs.count = -1, new_xs);
	return (new_xs);
}

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

t_intersections	intersect(t_sphere sphere, t_ray ray)
{
	t_intersections	xs;
	t_tuple			sphere_to_ray;
	double			d;
	double			a;
	double			b;

	(void)sphere;
	xs.intersections = NULL;
	d = discriminant(ray);
	if (d < -EPSILON)
		return (xs.count = 0, xs);
	xs.count = 2;
	xs.intersections = malloc(sizeof(t_intersection) * 2);
	if (!xs.intersections)
		return (xs.count = -1, xs);
	sphere_to_ray = substract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	xs.intersections[0].t = (-b - sqrt(d)) / (2 * a);
	xs.intersections[1].t = (-b + sqrt(d)) / (2 * a);
	xs.intersections[0].object = sphere.id;
	xs.intersections[1].object = sphere.id;
	return (xs);
}

bool	xs_grow(t_intersections *xs)
{
	t_intersection	*new_array;
	int				i;

	i = 0;
	new_array = malloc(sizeof(t_intersection) * (xs->capacity * 2));
	if (!new_array)
		return (false);
	while (i < xs->count)
	{
		new_array[i] = xs->intersections[i];
		i++;
	}
	free(xs->intersections);
	xs->intersections = new_array;
	xs->capacity *= 2;
	return (true);
}

bool	xs_push(t_intersections *xs, t_intersection i)
{
	if (xs->count == xs->capacity)
	{
		if (!xs_grow(xs))
			return (false);
	}
	xs->intersections[xs->count] = i;
	xs->count++;
	return (true);
}

bool	xs_append(t_intersections *dst, t_intersections src)
{
	int	i;

	i = 0;
	while (i < src.count)
	{
		if (!xs_push(dst, src.intersections[i]))
			return (false);
		i++;
	}
	free(src.intersections);
	return (true);
}

t_intersection	hit(t_intersections xs)
{
	t_intersection	closest;
	int				i;
	int				found;

	i = 0;
	found = 0;
	while (i < xs.count)
	{
		if (xs.intersections[i].t > 0)
		{
			if (!found || xs.intersections[i].t < closest.t)
			{
				closest = xs.intersections[i];
				found = 1;
			}
		}
		i++;
	}
	if (!found)
		closest.t = -1;
	return (closest);
}
