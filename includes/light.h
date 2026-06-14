/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:12 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/14 17:41:15 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "tuple.h"
# include "color.h"

typedef struct s_point_light
{
	t_tuple	position;
	t_color	intensity;
}	t_point_light;

t_point_light	point_light(t_tuple position, t_color intensity);

#endif