/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:45:35 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 14:47:13 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	intersection(double t, t_object *object)
{
	t_intersection	is;

	is.t = t;
	is.object = object;
	return (is);
}


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

void	intersect(t_object *object, t_ray ray, t_intersections *xs)
{
	t_ray			local_ray;

	local_ray = r_transform(ray, inversion(object->transformation));
	object->intersect(object, local_ray, xs);
}

void	intersect_plane(t_object *object, t_ray ray, t_intersections *xs)
{
	if (fabs(ray.direction.y) < EPSILON)
		return;
	xs_push(xs, intersection(-ray.origin.y / ray.direction.y, object));
}

bool	truncate_cylinder(t_object *object, t_ray ray, t_intersections *xs, double t)
{
	t_cylinder	*cylinder;
	double		y;

	cylinder = (t_cylinder *)object;
	y = ray.origin.y + ray.direction.y * t;
	if (y > cylinder->min && y < cylinder->max)
		if (!xs_push(xs, intersection(t, object)))
			return (false);
	return (true);
}

void	intersect_cylinder(t_object *object, t_ray ray, t_intersections *xs)
{
	double			a;
	double			b;
	double			c;
	double			d;

	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (equal(a, 0))
		return;
	b = 2 * (ray.origin.x * ray.direction.x +
			ray.origin.z * ray.direction.z);
	c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	d = b * b - 4 * a * c;
	if (d < 0)
		return;
	if (!truncate_cylinder(object, ray, xs, (-b - sqrt(d))/(2*a)))
		return;
	truncate_cylinder(object, ray, xs, (-b + sqrt(d))/(2*a));
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
		return;
	if (!xs_push(xs, intersection((-b - sqrt(d))/(2*a), object)))
		return;
	xs_push(xs, intersection((-b + sqrt(d))/(2*a), object));
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

bool	hit_exists(t_intersection hit)
{
	return (hit.t >= 0);
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
		if (xs.intersections[i].t >= 0)
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
