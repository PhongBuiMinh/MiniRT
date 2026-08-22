/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:13:11 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 15:46:03 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_canvas(t_canvas *canvas)
{
	if (!canvas)
		return ;
	if (canvas->pixels)
		free_pixels(canvas->pixels);
	free(canvas);
}

static void	cleanup_mlx(t_program *prog)
{
	if (!prog)
		return ;
	if (prog->img && prog->mlx)
	{
		mlx_delete_image(prog->mlx, prog->img);
		prog->img = NULL;
	}
	if (prog->mlx)
	{
		mlx_terminate(prog->mlx);
		prog->mlx = NULL;
	}
}

static void	cleanup_scene(t_scene *scene)
{
	int	i;

	if (!scene || !scene->objects)
		return ;
	i = 0;
	while (i < scene->object_idx)
	{
		free(scene->objects[i]);
		i++;
	}
	free(scene->objects);
	scene->objects = NULL;
	scene->object_cnt = 0;
	scene->object_idx = 0;
}

void	cleanup_program(t_program *prog)
{
	if (!prog)
		return ;
	cleanup_mlx(prog);
	cleanup_scene(&prog->scene);
}
