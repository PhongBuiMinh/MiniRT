/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 20:09:56 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	main(void)
{
	t_world		world;
	t_camera	camera;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_canvas	*canvas;

	world = world_default();
	camera = camera_init(11, 11, PI / 2);
	from = point(0, 0, -5);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	camera.transform = view_transform(from, to, up);
	canvas = render_scene(camera, world);
	t_print(canvas->pixels[5][5]);
	free_pixels(canvas->pixels);
}

//int	main(void)
//{
//	t_scene	scene;

//	if (!init_scene(&scene))
//		return (1);
//	if (!render_scene(&scene))
//		return (1);
//	canvas_to_ppm(&scene.canvas);
//	free_pixels(scene.canvas.pixels);
//	return (0);
//}
