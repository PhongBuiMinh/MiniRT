/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:48:33 by fbui-min          #+#    #+#             */
/*   Updated: 2026/05/23 18:08:07 by fbui-min         ###   ########.fr       */
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

// Writing and reading pixels
int	in_bounds(const t_canvas *c, int x, int y)
{
	return (x >= 0 && x < c->width && y >= 0 && y < c->height);
}

void	write_pixel(t_canvas *c, int x, int y, t_color color)
{
	int	index;

	if (!c || !c->pixels || !in_bounds(c, x, y))
		return;
	index = y * c->width + x;
	c->pixels[index] = color;
}

t_color	pixel_at(t_canvas *c, int x, int y)
{
	t_color	black;
	int		index;

	black.r = 0.0;
	black.g = 0.0;
	black.b = 0.0;
	if (!c || !c->pixels || !in_bounds(c, x, y))
		return (black);
	index = y * c->width + x;
	return (c->pixels[index]);
}

// Converting colors to bytes
int	to_byte(double v)
{
	int	n;

	if (v < 0.0)
		v = 0.0;
	if (v > 1.0)
		v = 1.0;
	n = (int)round(v * 255.0);
	if (n < 0)
		n = 0;
	if (n > 255)
		n = 255;
	return (n);
}

// Write one row with <= 70 chars per line
int	write_ppm_value(FILE *f, int value, int *len, int *first_in_line)
{
	char	buffer[32];
	int		needed;

	if (*first_in_line)
		needed = snprintf(buffer, sizeof(buffer), "%d", value);
	else
		needed = snprintf(buffer, sizeof(buffer), " %d", value);
	if (*len + needed > 70)
		return (0);
	fputs(buffer, f);
	*len += needed;
	*first_in_line = 0;
	return (1);
}

void	write_ppm_pixel(FILE *f, t_color col, int *len, int *first_in_line)
{
	int	vals[3];
	int	i;

	vals[0] = to_byte(col.r);
	vals[1] = to_byte(col.g);
	vals[2] = to_byte(col.b);
	i = 0;
	while (i < 3)
	{
		if (!write_ppm_value(f, vals[i], len, first_in_line))
		{
			fputc('\n', f);
			*len = 0;
			*first_in_line = 1;
			continue;
		}
		i++;
	}
}

void write_ppm_row(FILE *f, const t_canvas *c, int y)
{
	int	len;
	int	first_in_line;
	int	x;

	len = 0;
	first_in_line = 1;
	x = 0;
	while (x < c->width)
	{
		t_color col = pixel_at((t_canvas *)c, x, y);
		write_ppm_pixel(f, col, &len, &first_in_line);
		x++;
	}
	fputc('\n', f);
}

void	canvas_to_ppm(const t_canvas *c, const char *filename)
{
	FILE	*f;
	int		y;

	if (!c || !c->pixels || !filename)
		return;
	f = fopen(filename, "w");
	if (!f)
		return;
	/* header */
	fprintf(f, "P3\n");
	fprintf(f, "%d %d\n", c->width, c->height);
	fprintf(f, "255\n");
	y = 0;
	while (y < c->height)
	{
		write_ppm_row(f, c, y);
		y++;
	}
	fputc('\n', f);
	fclose(f);
}
