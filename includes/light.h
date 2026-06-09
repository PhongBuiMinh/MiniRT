/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:01:53 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 22:26:31 by bpetrovi         ###   ########.fr       */
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

typedef struct s_phong
{
	t_sphere	object;
	t_light		light;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside_obj;
}	t_phong;

t_tuple		phong_lightning(t_phong shade);
t_light		light_init(t_tuple pos, t_tuple intensity);

#endif