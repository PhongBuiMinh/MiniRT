/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:56:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:59:33 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H
# include "tuple.h"
# include "matrices.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

t_ray		r_init(t_tuple origin, t_tuple direction);
t_ray		r_transform(t_ray ray, t_matrix transformation);
t_tuple		r_pos(t_ray ray, float time);

#endif