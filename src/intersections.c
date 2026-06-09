/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:45:35 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:16:26 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	xs_init(void)
{
	t_intersections	new_xs;

	new_xs.capacity = 4;
	new_xs.count = 0;
	new_xs.err = false;
	new_xs.intersections = malloc(sizeof(t_intersection) * new_xs.capacity);
	if (new_xs.intersections == NULL)
		return (new_xs.err = true, new_xs);
	return (new_xs);
}

// TOO MANY VARIABLES + XS_PUSH FAILURE CAN BE HANDLED BETTER
t_intersections	xs_find(t_sphere sphere, t_ray ray)
{
	t_intersections	xs;
	t_intersection	is;
	t_tuple			sphere_to_ray;
	double			d;
	double			a;
	double			b;

	xs = xs_init();
	if (xs.err == true)
		return (xs);
	ray = r_transform(ray, inversion(sphere.transformation));
	d = discriminant(ray);
	if (d < -EPSILON)
		return (xs.count = 0, xs);
	sphere_to_ray = t_substract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	is.object = sphere;
	is.t = (-b - sqrt(d)) / (2 * a);
	xs_push(&xs, is);
	is.t = (-b + sqrt(d)) / (2 * a);
	xs_push(&xs, is);
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

void	xs_swap(t_intersections *xs, int i, int j)
{
	t_intersection	temp;

	temp = xs->intersections[i];
	xs->intersections[i] = xs->intersections[j];
	xs->intersections[j] = temp;
}

void	quick_sort(t_intersections *xs, int left, int right)
{
	int				pivot;
	int				i;
	int				j;

	if (left >= right)
		return ;
	pivot = (left + right) / 2;
	xs_swap(xs, pivot, right);
	i = left;
	j = left;
	while (j < right)
	{
		if (xs->intersections[j].t < xs->intersections[right].t)
		{
			xs_swap(xs, j, i);
			i++;
		}
		j++;
	}
	xs_swap(xs, i, right);
	quick_sort(xs, left, i - 1);
	quick_sort(xs, i + 1, right);
}

void	xs_sort(t_intersections *xs)
{
	quick_sort(xs, 0, xs->count - 1);
}

bool	xs_push(t_intersections *xs, t_intersection i)
{
	if (xs->count == xs->capacity)
	{
		if (!xs_grow(xs))
			return (xs->err = true, false);
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
			return (free(src.intersections), free(dst->intersections), false);
		i++;
	}
	free(src.intersections);
	return (true);
}

t_intersection	xs_hit(t_intersections xs)
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