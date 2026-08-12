/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:00:07 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/12 14:59:40 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	color(double r, double g, double b)
{
	return ((t_tuple){.x = r, .y = g, .z = b, .w = 0});
}

int	clamp_color(int c)
{
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}

int	scale_color(float c)
{
	return (clamp_color((int)round(c * 255)));
}

int	color_to_int(t_tuple color)
{
	int	r;
	int	g;
	int	b;

	r = scale_color((float)color.x);
	g = scale_color((float)color.y);
	b = scale_color((float)color.z);
	return (r << 24 | g << 16 | b << 8 | 255);
}
