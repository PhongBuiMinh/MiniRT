/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:13:15 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:15:46 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "tuple.h"
# include "rays.h"
# include "objects.h"

typedef struct s_intersection
{
	double		t;
	t_object	*object;
}	t_intersection;

typedef struct s_intersections
{
	t_intersection	*intersections;
	bool			err;
	int				capacity;
	int				count;
}	t_intersections;


t_intersections	xs_init(void);
t_intersection	intersection(double t, t_object *object);
t_intersection	hit(t_intersections xs);
void			xs_sort(t_intersections *xs);
void			intersect(t_object *object, t_ray ray, t_intersections *xs);
void			intersect_sphere(t_object *object, t_ray ray,
					t_intersections *xs);
void			intersect_plane(t_object *object, t_ray ray,
					t_intersections *xs);
void			intersect_cylinder(t_object *object, t_ray ray,
					t_intersections *xs);
bool			truncate_cylinder(t_object *object, t_ray ray,
					t_intersections *xs, double t);
bool			check_caps(t_ray ray, double t);
bool			hit_exists(t_intersection hit);
bool			xs_push(t_intersections *xs, t_intersection i);

// 				NOT USED FOR NOW
//bool			xs_append(t_intersections *dst, t_intersections src);


#endif