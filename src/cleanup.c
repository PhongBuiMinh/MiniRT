/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:13:11 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/12 13:59:32 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fatal(char *msg, t_program *prog)
{
	if (prog)
		cleanup_program(prog);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	free_canvas(t_canvas *canvas)
{
	int i;

	if (!canvas)
		return ;
	if (!canvas->pixels)
		return ;
	i = 0;
	while (i < canvas->height)
	{
		free(canvas->pixels[i]);
		i++;
	}
	free(canvas->pixels);
	free(canvas);
}

// static void	cleanup_canvas(t_canvas *canvas)
// {
// 	int	y;

// 	if (!canvas || !canvas->pixels)
// 		return ;
// 	y = 0;
// 	while (y < canvas->height)
// 		free(canvas->pixels[y++]);
// 	free(canvas->pixels);
// 	canvas->pixels = NULL;
// }

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
	// cleanup_canvas(&prog->canvas);
	cleanup_mlx(prog);
	cleanup_scene(&prog->scene);
}
