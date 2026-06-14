/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 22:08:58 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*init_spheres(int obj_cnt)
{
	t_sphere	*spheres;
	int			i;

	spheres = malloc(sizeof(t_sphere) * obj_cnt);
	if (!spheres)
		return (NULL);
	i = 0;
	while (i < obj_cnt)
	{
		spheres[i] = sphere(i);
		i++;
	}
	return (spheres);
}

t_world	scene_with_three_spheres(void)
{
	t_world	new_world;

	new_world.light = light_init(point(-10, 10, -10), color(1, 1, 1));
	new_world.object_cnt = 6;
	new_world.spheres = init_spheres(new_world.object_cnt);
	/* Floor */
	new_world.spheres[0].transformation = scaling(10, 0.01, 10);
	new_world.spheres[0].material = material();
	new_world.spheres[0].material.color = color(1, 0.9, 0.9);
	new_world.spheres[0].material.specular = 0;
	/* Left wall */
	new_world.spheres[1].transformation = m_multiply(translation(0, 0, 5),
			m_multiply(rotation_y(-PI / 4), m_multiply(rotation_x(PI / 2),
					scaling(10, 0.01, 10))));
	new_world.spheres[1].material = new_world.spheres[0].material;
	/* Right wall */
	new_world.spheres[2].transformation = m_multiply(translation(0, 0, 5),
			m_multiply(rotation_y(PI / 4), m_multiply(rotation_x(PI / 2),
					scaling(10, 0.01, 10))));
	new_world.spheres[2].material = new_world.spheres[0].material;
	/* Middle sphere */
	new_world.spheres[3].transformation = translation(-0.5, 1, 0.5);
	new_world.spheres[3].material = material();
	new_world.spheres[3].material.color = color(0.1, 1, 0.5);
	new_world.spheres[3].material.diffuse = 0.7;
	new_world.spheres[3].material.specular = 0.3;
	/* Right sphere */
	new_world.spheres[4].transformation = m_multiply(translation(1.5, 0.5,
				-0.5), scaling(0.5, 0.5, 0.5));
	new_world.spheres[4].material = material();
	new_world.spheres[4].material.color = color(0.5, 1, 0.1);
	new_world.spheres[4].material.diffuse = 0.7;
	new_world.spheres[4].material.specular = 0.3;
	/* Left sphere */
	new_world.spheres[5].transformation = m_multiply(translation(-1.5, 0.33,
				-0.75), scaling(0.33, 0.33, 0.33));
	new_world.spheres[5].material = material();
	new_world.spheres[5].material.color = color(1, 0.8, 0.1);
	new_world.spheres[5].material.diffuse = 0.7;
	new_world.spheres[5].material.specular = 0.3;
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
	camera = camera_init(500, 200, PI / 3);
	from = point(0, 1.5, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	camera.transform = view_transform(from, to, up);
	canvas = render_scene(camera, world);
	canvas_to_ppm(canvas);
	free(world.spheres);
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
