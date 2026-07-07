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
#include "scene.h"

# define WIDTH 350
# define HEIGHT 250

void	fatal(char *msg, t_program *prog)
{
	// cleanup_program(prog);
	(void)prog;
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	render_minirt(t_program *prog)
{
	// render(camera, world, canvas);
	mlx_put_image_to_window(prog->mlx.mlx, prog->mlx.win,
		prog->mlx.img, 0, 0);
}

// int	build_world_from_scene(t_scene *scene, t_world *world, t_camera *camera)
// {
// 	(void)scene;
// 	(void)world;
// 	(void)camera;
// 	// 1. Set up the camera
// 	// 2. Set up world with objects
// 	// 3. Set up lights
// 	return (0);
// }

t_canvas	canvas_new(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.pixels = malloc(sizeof(t_color) * width * height);
	if (!canvas.pixels)
		canvas.pixels = NULL;
	return (canvas);
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
	if (!build_world_from_scene(&prog.scene, &prog.world, &prog.camera))
		fatal("Failed to build world from scene", &prog);
	prog.canvas = canvas_new(prog.camera.h_size, prog.camera.v_size);
	if (!prog.canvas.pixels)
		fatal("Failed to allocate canvas", &prog);
	// prog.camera.h_size = 350;
	// prog.camera.v_size = 250;
	init_render(&prog);
	init_img(&prog);
	render_minirt(&prog);
	mlx_hook(prog.mlx.win, 17, 0, (int (*)(void *))exit_minirt, &prog);
	mlx_key_hook(prog.mlx.win, key_hook, &prog);
	// mlx_mouse_hook(prog.mlx.win, mouse_hook, prog);
	mlx_loop(prog.mlx.mlx);
}

// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (1);
// 	win = mlx_new_window(mlx, 800, 600, "MLX Test");
// 	if (!win)
// 		return (1);
// 	mlx_loop(mlx);
// 	return (0);
// }
