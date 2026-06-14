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

#include <stdlib.h>
#include "mlx.h"
// #include "scene.h"
// #include "world.h"
// #include "camera.h"
#include "color.h"

typedef struct	s_program
{
	t_scene		scene;
	t_world		world;
	t_camera	cam;
	t_canvas	canvas;
	t_mlx		mlx;
}	t_program;

int	close_hook(t_program *prog)
{
	cleanup_program(prog);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_program *prog)
{
	if (keycode == 53)
		close_hook(prog);
	return (0);
}

void	init_mlx_and_display(t_program *prog)
{
	prog->mlx.mlx = mlx_init();
	if (!prog->mlx.mlx)
		fatal("mlx_init failed", prog);
	prog->mlx.win = mlx_new_window(prog->mlx.mlx,
			prog->cam.hsize, prog->cam.vsize, "miniRT");
	if (!prog->mlx.win)
		fatal("mlx_new_window failed", prog);
	prog->mlx.img = mlx_new_image(prog->mlx.mlx,
			prog->cam.hsize, prog->cam.vsize);
	if (!prog->mlx.img)
		fatal("mlx_new_image failed", prog);
	prog->mlx.addr = mlx_get_data_addr(prog->mlx.img,
			&prog->mlx.bpp, &prog->mlx.line_len, &prog->mlx.endian);
	if (!prog->mlx.addr)
		fatal("mlx_get_data_addr failed", prog);
	// copy from engine canvas to MLX image buffer
	// or render directly into MLX buffer instead of t_canvas
	mlx_put_image_to_window(prog->mlx.mlx, prog->mlx.win,
		prog->mlx.img, 0, 0);
	mlx_hook(prog->mlx.win, 17, 0, (int (*)(void *))close_hook, prog);
	mlx_key_hook(prog->mlx.win, key_hook, prog);
	mlx_loop(prog->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./miniRT <scene.rt>\n", 2);
		return (EXIT_FAILURE);
	}
	ft_bzero(&prog, sizeof(t_program));
	if (!parse_scene_file(argv[1], &prog.scene))
		fatal("Failed to parse scene file", &prog);
	if (!build_world_from_scene(&prog.scene, &prog.world, &prog.cam))
		fatal("Failed to build world from scene", &prog);
	prog.canvas = canvas_new(prog.cam.hsize, prog.cam.vsize); // RENDER INTO CANVAS USING ENGINE (ray tracer core)
	if (!prog.canvas.pixels)
		fatal("Failed to allocate canvas", &prog);
	render(&prog.cam, &prog.world, &prog.canvas);
	init_mlx_and_display(&prog);
	return (EXIT_SUCCESS);
}
