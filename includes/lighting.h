/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:40 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/14 17:42:29 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "material.h"
# include "light.h"
# include "tuple.h"
# include "color.h"

typedef struct s_light_params
{
	t_material		material;
	t_point_light	light;
	t_tuple			point_pos;
	t_tuple			eyev;
	t_tuple			normalv;
	int				in_shadow;
}	t_light_params;

t_color	lighting(t_light_params p);

#endif