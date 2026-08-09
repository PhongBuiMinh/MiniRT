/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:09:55 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/09 21:01:01 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_program *prog)
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
