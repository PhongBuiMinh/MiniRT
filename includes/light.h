/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:01:53 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/04 21:21:28 by bpetrovi         ###   ########.fr       */
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

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

t_light		point_light(t_tuple pos, t_tuple intensity);
t_material	material(void);

#endif