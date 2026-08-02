/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:08:07 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/02 20:43:45 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	canvas_new(int width, int height)
{
	t_canvas	canvas;
	int			y;

	canvas.width = width;
	canvas.height = height;
	canvas.pixels = malloc(sizeof(t_tuple *) * height);
	if (!canvas.pixels)
		return (canvas.width = 0, canvas.height = 0, canvas);
	y = -1;
	while (++y < height)
	{
		canvas.pixels[y] = malloc(sizeof(t_tuple) * width);
		if (!canvas.pixels[y])
		{
			while (--y >= 0)
				free(canvas.pixels[y]);
			free(canvas.pixels);
			canvas.pixels = NULL;
			canvas.width = 0;
			canvas.height = 0;
			return (canvas);
		}
		ft_bzero(canvas.pixels[y], sizeof(t_tuple) * width);
	}
	return (canvas);
}
