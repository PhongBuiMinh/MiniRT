/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 15:57:44 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_scene(t_scene *scene)
{
	t_canvas	canvas;
	double		wall_size;

	wall_size = 5;
	if (!init_canvas(&canvas, 400, 400))
		return (0);
	scene->canvas = canvas;
	scene->origin = point(0, 0, -5);
	scene->sphere = sphere(5);
	scene->sphere.material = material();
	scene->sphere.material.color = color(1, 0.2, 1);
	scene->light = light_init(point(10, 10, -10), color(1, 1, 1));
	scene->half = wall_size / 2;
	scene->pixel_size = wall_size / canvas.width;
	scene->wall_z = 5;
	return (1);
}


int	main(void)
{
	t_tuple	from;
	t_tuple	up;
	t_tuple	to;

	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);
	m_print(view_transform(from, to, up));
	printf("--------------\n");
	return (0);
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
