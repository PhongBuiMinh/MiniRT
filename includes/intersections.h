/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:13:15 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 19:17:33 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "tuple.h"

typedef struct s_intersection
{
	double	t;
	int		object;
}	t_intersection;

typedef struct s_intersections
{
	t_intersection	*intersections;
	bool			err;
	int				capacity;
	int				count;
}	t_intersections;


t_intersections	intersect(t_sphere sphere, t_ray ray);
t_intersections	xs_init(void);
t_intersection	hit(t_intersections xs);
t_tuple			normal_at(t_sphere sphere, t_tuple intersect_point);
t_tuple			reflect(t_tuple in, t_tuple normal);
bool			xs_append(t_intersections *dst, t_intersections src);
bool			xs_push(t_intersections *xs, t_intersection i);
bool			xs_grow(t_intersections *xs);
void			xs_sort(t_intersections *xs);

#endif