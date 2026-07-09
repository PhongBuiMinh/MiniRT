/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:17:25 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 13:49:42 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "tuple.h"

t_tuple			cross(t_tuple a, t_tuple b);
t_tuple			normalize(t_tuple tuple);
t_tuple			normal_at(t_object *object, t_tuple world_p);
t_tuple			normal_at_sphere(t_tuple is_point);
t_tuple			normal_at_plane(t_tuple is_point);
t_tuple         normal_at_cylinder(t_tuple is_point);
t_tuple			reflect(t_tuple in, t_tuple normal);
double			magnitude(t_tuple	tuple);
double			dot(t_tuple a, t_tuple b);

#endif