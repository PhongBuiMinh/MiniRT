/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:38:38 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:24 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"
# include "sphere.h"

# define MAX_INTERSECTIONS 8

typedef struct s_intersection
{
	double		t;
	t_sphere	*object;
}	t_intersection;

typedef struct s_intersections
{
	int				count;
	t_intersection	xs[MAX_INTERSECTIONS];
}	t_intersections;

void			intersections_clear(t_intersections *xs);
void			intersections_add(t_intersections *xs,
					double t, t_sphere *object);
t_intersection	*hit(t_intersections *xs);

void			sphere_intersect(const t_sphere *s,
					t_ray r, t_intersections *xs);

#endif