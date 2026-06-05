/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:55:51 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/05 19:56:25 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_point_light	point_light(t_tuple position, t_color intensity)
{
	t_point_light	l;

	l.position = position;
	l.intensity = intensity;
	return (l);
}

