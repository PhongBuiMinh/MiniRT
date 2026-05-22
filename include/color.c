/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:48:33 by fbui-min          #+#    #+#             */
/*   Updated: 2026/05/22 20:06:38 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(double r, double g, double b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color	add_color(t_color a, t_color b)
{
	return (color(a.r + b.r, a.g + b.g, a.b + b.b));
}

t_color	sub_color(t_color a, t_color b)
{
	return (color(a.r - b.r, a.g - b.g, a.b - b.b));
}

t_color	mul_color_scalar(t_color c, double s)
{
	return (color(c.r * s, c.g * s, c.b * s));
}

t_color	hadamard_color(t_color a, t_color b)
{
	return (color(a.r * b.r, a.g * b.g, a.b * b.b));
}

t_canvas	canvas_new(int width, int height)
{
	t_canvas	c;
	int			i;

	c.width = width;
	c.height = height;
	c.pixels = (t_color *)malloc(sizeof(t_color) * width * height);
	if (!c.pixels)
	{
		c.width = 0;
		c.height = 0;
		return (c);
	}
	i = 0;
	while (i < width * height)
	{
		c.pixels[i] = color(0.0, 0.0, 0.0);
		i++;
	}
	return (c);
}

void	canvas_destroy(t_canvas *c)
{
	if (c && c->pixels)
	{
		free(c->pixels);
		c->pixels = NULL;
		c->width = 0;
		c->height = 0;
	}
}
