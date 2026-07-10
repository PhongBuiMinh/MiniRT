/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 18:56:53 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	scene_with_three_spheres(void)
{
	t_world	new_world;
	int		i;

	new_world.light = light_init(point(-10, 10, -10), color(1, 1, 1));
	new_world.object_cnt = 4;
	i = 1;
	// FLOOR
	new_world.objects[0] = plane_create(0);
	while (i < new_world.object_cnt)
	{
		new_world.objects[i] = sphere_create(i);
		i++;
	}
	new_world.object_cnt++;
	new_world.objects[i] = cylinder_create(i);
	// /* Left wall */
	// new_world.objects[1]->transformation = m_multiply(translation(0, 0, 5),
	// 		m_multiply(rotation_y(-PI / 4), m_multiply(rotation_x(PI / 2),
	// 				scaling(10, 0.01, 10))));
	// new_world.objects[1]->material = new_world.objects[0]->material;
	// /* Right wall */
	// new_world.objects[2]->transformation = m_multiply(translation(0, 0, 5),
	// 		m_multiply(rotation_y(PI / 4), m_multiply(rotation_x(PI / 2),
	// 				scaling(10, 0.01, 10))));
	// new_world.objects[2]->material = new_world.objects[0]->material;
	/* Middle sphere */
	new_world.objects[1]->transformation = translation(-0.5, 1, 0.5);
	new_world.objects[1]->material = material();
	new_world.objects[1]->material.color = color(0.1, 1, 0.5);
	new_world.objects[1]->material.diffuse = 0.7;
	new_world.objects[1]->material.specular = 0.3;
	/* Right sphere */
	new_world.objects[2]->transformation = m_multiply(translation(1.5, 0.5,
				-0.5), scaling(0.5, 0.5, 0.5));
	new_world.objects[2]->material = material();
	new_world.objects[2]->material.color = color(0.5, 1, 0.1);
	new_world.objects[2]->material.diffuse = 0.7;
	new_world.objects[2]->material.specular = 0.3;
	/* Left sphere */
	new_world.objects[3]->transformation = m_multiply(translation(-1.5, 0.33,
				-0.75), scaling(0.33, 0.33, 0.33));
	new_world.objects[3]->material = material();
	new_world.objects[3]->material.color = color(1, 0.8, 0.1);
	new_world.objects[3]->material.diffuse = 0.7;
	new_world.objects[3]->material.specular = 0.3;
	/* Cylinder */
	new_world.objects[4]->transformation = translation(2, 2, 2);
	new_world.objects[4]->material.color = color(1, 0.8, 0.1);
	return (new_world);
}

int	main(void)
{
	t_world		world;
	t_camera	camera;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_canvas	*canvas;

	world = scene_with_three_spheres();
	camera = camera_init(400, 400, PI / 3);
	from = point(0, 1.5, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	camera.transform = view_transform(from, to, up);
	canvas = render_scene(camera, world);
	canvas_to_ppm(canvas);
	free_objects(world.objects, world.object_cnt);
	free_pixels(canvas->pixels);
	free(canvas);
}

// int	main(void)
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
