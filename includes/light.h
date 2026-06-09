/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:01:53 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:55:05 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "tuple.h"

typedef struct s_light
{
	t_tuple	intensity;
	t_tuple	pos;
}	t_light;

typedef struct t_shade
{
	t_material	m;
	t_light		light;
	t_tuple		p;
	t_tuple		eyev;
	t_tuple		normalv;
}	t_shade;

t_tuple		lighting(t_shade shade);
t_light		point_light(t_tuple pos, t_tuple intensity);

#endif