/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:35:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/09 12:50:36 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_tuple	color(float r, float g, float b)
{
	return (vector(r, g, b));
}

void	write_pixel(t_canvas *canvas, int x, int y, t_tuple color)
{
	canvas->pixels[x][y] = color;
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

int	init_canvas(t_canvas *canvas, int x, int y)
{
	canvas->pixels = init_pixels(x, y);
	if (!canvas->pixels)
		return (0);
	canvas->width = x;
	canvas->height = y;
	return (1);
}

int	clamp_color(int c)
{
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}

//int	ft_fprintf(char *string, )
//{

//}

//int	canvas_to_ppm(t_canvas *canvas, char *file_name)
//{
//	int	fd;

//	fd = open(file, O_RDWR);
//	if (!fd)
//		return (perror("Error: "), 0);
//	write(fd, "P3\n", );
//	return (1);
//}
