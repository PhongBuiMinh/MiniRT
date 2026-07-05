/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:08:07 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 14:17:34 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_render(t_program *prog)
{
	prog->mlx.mlx = mlx_init();
	if (!prog->mlx.mlx)
		fatal("mlx_init failed", prog);
	prog->mlx.win = mlx_new_window(
			prog->mlx.mlx,
			prog->camera.h_size,
			prog->camera.v_size,
			"MiniRT"
			);
	if (!prog->mlx.win)
		fatal("mlx_new_window failed", prog);
}

void	init_img(t_program *prog)
{
	prog->mlx.img = mlx_new_image(
			prog->mlx.mlx,
			prog->camera.h_size,
			prog->camera.v_size
			);
	if (!prog->mlx.img)
		fatal("mlx_new_image failed", prog);
	prog->mlx.addr = mlx_get_data_addr(
			prog->mlx.img,
			&prog->mlx.bpp,
			&prog->mlx.line_len,
			&prog->mlx.endian
			);
	if (!prog->mlx.addr)
		fatal("mlx_get_data_addr failed", prog);
}
