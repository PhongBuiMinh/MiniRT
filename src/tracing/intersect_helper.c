/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:45:35 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:17:47 by bpetrovi         ###   ########.fr       */
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

bool	truncate_cylinder(t_object *object, t_ray ray,
		t_intersections *xs, double t)
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

bool	check_caps(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + ray.direction.x * t;
	z = ray.origin.z + ray.direction.z * t;
	return (x * x + z * z <= 1);
}
