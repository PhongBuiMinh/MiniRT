/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:53:54 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/28 21:54:39 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	clamp_channel(double v)
{
	if (v < 0.0)
		return (0);
	if (v > 1.0)
		return (255);
	return ((int)(v * 255.0));
}

int	color_to_int(t_tuple color)
{
	int	r;
	int	g;
	int	b;

	r = clamp_channel(color.x);
	g = clamp_channel(color.y);
	b = clamp_channel(color.z);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	render_minirt(t_program *prog)
{
	t_canvas	*rendered;
	int			x;
	int			y;

	// rendered = render_scene(prog->camera, prog->world);
	rendered = 0;
	if (!rendered)
		fatal("render_scene failed", prog);
	y = 0;
	while (y < rendered->height)
	{
		x = 0;
		while (x < rendered->width)
		{
			mlx_put_pixel(prog->mlx.img, x, y, color_to_int(rendered->pixels[y][x]));
			x++;
		}
		y++;
	}
	mlx_image_to_window(prog->mlx.mlx, prog->mlx.img, 0, 0);
}
