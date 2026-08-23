/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:10:49 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/23 14:57:03 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_minirt(void *param)
{
	t_program	*prog;

	prog = (t_program *)param;
	cleanup_program(prog);
	exit(EXIT_SUCCESS);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_program	*prog;

	prog = (t_program *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup_program(prog);
		exit(EXIT_SUCCESS);
	}
}
