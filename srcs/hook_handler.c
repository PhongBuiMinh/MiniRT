/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:10:49 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/03 07:33:51 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_minirt(t_program *prog)
{
	// cleanup_program(prog);
	if (prog->mlx.img)
		mlx_destroy_image(prog->mlx.mlx, prog->mlx.img);
	if (prog->mlx.win)
		mlx_destroy_window(prog->mlx.mlx, prog->mlx.win);
	if (prog->mlx.mlx)
		free(prog->mlx.mlx);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_program	*prog;

	prog = (t_program *)param;
	if (keycode == 53)
		exit_minirt(prog);
	return (0);
}
