/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 23:00:44 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//int	init_scene(t_scene *scene)
//{
//	t_canvas	canvas;
//	double		wall_size;

//	wall_size = 5;
//	if (!init_canvas(&canvas, 400, 400))
//		return (0);
//	scene->canvas = canvas;
//	scene->origin = point(0, 0, -5);
//	scene->sphere = sphere(5);
//	scene->sphere.material = material();
//	scene->sphere.material.color = color(1, 0.2, 1);
//	scene->light = light_init(point(10, 10, -10), color(1, 1, 1));
//	scene->half = wall_size / 2;
//	scene->pixel_size = wall_size / canvas.width;
//	scene->wall_z = 5;
//	return (1);
//}


int	main(void)
{
	t_phong			phong;
	t_world			world;
	t_intersections	xs;
	t_ray			ray;

	world = world_default();
	ray = r_init(point(0, 0, -5), vector(0, 0, 1));
	xs = xs_find(world.spheres[0], ray);
	printf("%f\n", xs.intersections[0].t);
	if (xs.err == true)
		return (free(world.spheres), 1);
	phong = phong_computations(hit(xs), ray);
	t_print(phong.point);
	t_print(phong.normalv);
	t_print(phong.eyev);
	phong.light = world.light;
	t_print(phong_lightning(phong));
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
