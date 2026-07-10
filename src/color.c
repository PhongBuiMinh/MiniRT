/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:00:07 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:00:39 by bpetrovi         ###   ########.fr       */
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
