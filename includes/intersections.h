/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:13:15 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/31 18:40:23 by bpetrovi         ###   ########.fr       */
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
	t_intersection	intersections[2];
	int				count;
}	t_intersections;


t_intersections	intersect(t_sphere sphere, t_ray ray);


#endif