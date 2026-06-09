/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:17:25 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 22:17:28 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "tuple.h"

t_tuple			cross(t_tuple a, t_tuple b);
t_tuple			normalize(t_tuple tuple);
t_tuple			normal_at(t_sphere sphere, t_tuple world_p);
t_tuple			reflect(t_tuple in, t_tuple normal);
double			magnitude(t_tuple	tuple);
double			dot(t_tuple a, t_tuple b);

#endif