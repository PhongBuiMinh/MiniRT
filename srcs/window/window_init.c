/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:09:55 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/10 22:29:18 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_program *prog)
{
	int	width;
	int	height;

	width = prog->camera.h_size;
	height = prog->camera.v_size;
	prog->mlx = mlx_init(width, height, "miniRT", false);
	if (!prog->mlx)
		fatal("Failed to initialize MLX42", prog);
}

void	init_img(t_program *prog)
{
	int	width;
	int	height;

	width = prog->camera.h_size;
	height = prog->camera.v_size;
	prog->img = mlx_new_image(prog->mlx, width, height);
	if (!prog->img)
		fatal("Failed to create image", prog);
	if (mlx_image_to_window(prog->mlx, prog->img, 0, 0) < 0)
		fatal("Failed to put image to window", prog);
}
