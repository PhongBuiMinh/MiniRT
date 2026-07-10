/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:35:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:25:44 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_pixel(t_canvas *canvas, int x, int y, t_tuple color)
{
	if (x > canvas->width - 1 || y > canvas->height - 1 || x < 0 || y < 0)
		return ;
	canvas->pixels[y][x] = color;
}

void	free_pixels(t_tuple **pixels)
{
	int	i;

	i = 0;
	if (!pixels)
		return ;
	while (pixels[i])
	{
		free(pixels[i]);
		i++;
	}
	free(pixels);
}

t_tuple	**init_pixels(int x, int y)
{
	t_tuple	**pixels;
	int		i;
	int		d;

	pixels = malloc((y + 1) * sizeof(t_tuple *));
	if (!pixels)
		return (NULL);
	pixels[y] = NULL;
	i = 0;
	while (i < y)
	{
		d = 0;
		pixels[i] = malloc(x * sizeof(t_tuple));
		if (!pixels[i])
			return (free_pixels(pixels), NULL);
		while (d < x)
		{
			pixels[i][d] = color(0, 0, 0);
			d++;
		}
		i++;
	}
	return (pixels);
}

t_canvas	*init_canvas(int x, int y)
{
	t_canvas	*canvas;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->pixels = init_pixels(x, y);
	if (!canvas->pixels)
		return (0);
	canvas->width = x;
	canvas->height = y;
	return (canvas);
}

// WONT BE NEEEDED OTHER THAN FOR TESTING

void	canvas_to_ppm(t_canvas *canvas)
{
	int	y;
	int	x;
	int	line;

	printf("P3\n%i %i\n255\n", canvas->width, canvas->height);
	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		line = 0;
		while (x < canvas->width)
		{
			if (line + 4 > 70)
			{
				printf("\n");
				line = 0;
			}
			line += printf("%i ", scale_color(canvas->pixels[y][x].x));
			if (line + 4 > 70)
			{
				printf("\n");
				line = 0;
			}
			line += printf("%i ", scale_color(canvas->pixels[y][x].y));
			if (line + 4 > 70)
			{
				printf("\n");
				line = 0;
			}
			line += printf("%i ", scale_color(canvas->pixels[y][x].z));
			x++;
		}
		printf("\n");
		y++;
	}
}
