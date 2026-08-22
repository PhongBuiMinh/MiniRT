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

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./miniRT <scene.rt>\n", 2), EXIT_FAILURE);
	ft_bzero(&prog, sizeof(prog));
	if (!parse_scene_file(argv[1], &prog.scene))
		fatal("Failed to parse scene file: missing element or object.", &prog);
	if (!build_world_from_scene(&prog.scene, &prog.world, &prog.camera))
		fatal("Failed to build world/camera", &prog);
	render_minirt(&prog);
	mlx_close_hook(prog.mlx, exit_minirt, &prog);
	mlx_key_hook(prog.mlx, key_hook, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
