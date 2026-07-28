/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:08:07 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/28 21:56:21 by fbui-min         ###   ########.fr       */
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

void	init_render(t_program *prog)
{
	prog->mlx.mlx = mlx_init(prog->camera.h_size,
			prog->camera.v_size, "miniRT", true);
	if (!prog->mlx.mlx)
		fatal("Failed to initialize MLX42", prog);
}

void	init_img(t_program *prog)
{
	prog->mlx.img = mlx_new_image(prog->mlx.mlx,
			prog->camera.h_size, prog->camera.v_size);
	if (!prog->mlx.img)
		fatal("Failed to create image", prog);
	if (mlx_image_to_window(prog->mlx.mlx, prog->mlx.img, 0, 0) < 0)
		fatal("Failed to display image", prog);
}
