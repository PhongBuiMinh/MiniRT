/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:55:01 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/13 18:46:35 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "intersection.h"

/* utility */
void	intersections_clear(t_intersections *xs)
{
	if (!xs)
		return;
	xs->count = 0;
}

void	intersections_add(t_intersections *xs, double t, t_sphere *object)
{
	if (!xs || xs->count >= MAX_INTERSECTIONS)
		return;
	xs->xs[xs->count].t = t;
	xs->xs[xs->count].object = object;
	xs->count++;
}

t_intersection	*hit(t_intersections *xs)
{
	int				i;
	t_intersection	*best;

	if (!xs || xs->count == 0)
		return (NULL);
	best = NULL;
	i = 0;
	while (i < xs->count)
	{
		if (xs->xs[i].t >= 0.0
			&& (best == NULL || xs->xs[i].t < best->t))
			best = &xs->xs[i];
		i++;
	}
	return (best);
}

/* solve ray–unit-sphere quadratic in object space, return 0/1 */
static int	sphere_solve_quadratic(t_ray r, double *t1, double *t2)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	sphere_to_ray = sub_tuple(r.origin, point(0, 0, 0));
	a = dot(r.direction, r.direction);
	b = 2.0 * dot(r.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1.0;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (0);
	*t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	*t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	return (1);
}

/* intersect ray with unit sphere in object space */
void	sphere_intersect(const t_sphere *s, t_ray r, t_intersections *xs)
{
	t_ray	r_obj;
	double	t1;
	double	t2;

	if (!s || !xs)
		return;
	r_obj.origin = matrix4_mul_tuple(s->inverse, r.origin);
	r_obj.direction = matrix4_mul_tuple(s->inverse, r.direction);
	if (!sphere_solve_quadratic(r_obj, &t1, &t2))
		return;
	intersections_add(xs, t1, (t_sphere *)s);
	intersections_add(xs, t2, (t_sphere *)s);
}
