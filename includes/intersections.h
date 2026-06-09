/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:13:15 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 22:49:05 by bpetrovi         ###   ########.fr       */
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
	t_sphere	object;
}	t_intersection;

typedef struct s_intersections
{
	t_intersection	*intersections;
	bool			err;
	int				capacity;
	int				count;
}	t_intersections;


t_intersections	xs_find(t_sphere sphere, t_ray ray);
t_intersections	xs_init(void);
t_intersection	hit(t_intersections xs);
bool			xs_append(t_intersections *dst, t_intersections src);
bool			xs_push(t_intersections *xs, t_intersection i);
void			xs_sort(t_intersections *xs);

#endif