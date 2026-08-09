/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/8 12:45:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/14 13:18:16 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cleanup_program(t_program *prog)
{
	int	y;

	if (!prog)
		return ;
	if (prog->canvas.pixels)
	{
		y = 0;
		while (y < prog->canvas.height)
			free(prog->canvas.pixels[y++]);
		free(prog->canvas.pixels);
		prog->canvas.pixels = NULL;
	}
	if (prog->mlx.img && prog->mlx.mlx)
	{
		mlx_delete_image(prog->mlx.mlx, prog->mlx.img);
		prog->mlx.img = NULL;
	}
	if (prog->mlx.mlx)
	{
		mlx_terminate(prog->mlx.mlx);
		prog->mlx.mlx = NULL;
	}
	if (prog->scene.objects)
	{
		int i = 0;
		while (i < prog->scene.object_cnt)
			free(prog->scene.objects[i++]);
		free(prog->scene.objects);
		prog->scene.objects = NULL;
		prog->scene.object_cnt = 0;
	}
}

void	fatal(char *msg, t_program *prog)
{
	if (prog)
		cleanup_program(prog);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./miniRT <scene.rt>\n", 2), EXIT_FAILURE);

	ft_bzero(&prog, sizeof(prog));

	if (!parse_scene_file(argv[1], &prog.scene))
		fatal("Failed to parse scene file", &prog);

	if (!build_world_from_scene(&prog.scene, &prog.world, &prog.camera))
		fatal("Failed to build world/camera", &prog);

	prog.canvas = canvas_new(prog.camera.h_size, prog.camera.v_size);
	if (!prog.canvas.pixels)
		fatal("Failed to allocate canvas", &prog);

	init_render(&prog);
	init_img(&prog);
	render_minirt(&prog);

	mlx_close_hook(prog.mlx.mlx, exit_minirt, &prog);
	mlx_key_hook(prog.mlx.mlx, key_hook, &prog);
	mlx_loop(prog.mlx.mlx);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_program	prog;

// 	if (argc != 2)
// 		return (ft_putstr_fd("Usage: ./miniRT <scene.rt>\n", 2), EXIT_FAILURE);
// 	ft_bzero(&prog, sizeof(prog));
// 	if (!parse_scene_file(argv[1], &prog.scene))
// 		fatal("Failed to parse scene file", &prog);
// 	if (!build_world_from_scene(&prog.scene, &prog.world, &prog.camera))
// 		fatal("Failed to build world", &prog);
// 	prog.canvas = canvas_new(prog.camera.h_size, prog.camera.v_size);
// 	if (!prog.canvas.pixels)
// 		fatal("Failed to allocate canvas", &prog);
// 	init_render(&prog);
// 	init_img(&prog);
// 	render_minirt(&prog);
// 	mlx_close_hook(prog.mlx.mlx, exit_minirt, &prog);
// 	mlx_key_hook(prog.mlx.mlx, key_hook, &prog);
// 	mlx_loop(prog.mlx.mlx);
// 	return (0);
// }
