/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 19:46:18 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
//	scene->light = point_light(point(10, 10, -10), color(1, 1, 1));
//	scene->half = wall_size / 2;
//	scene->pixel_size = wall_size / canvas.width;
//	scene->wall_z = 5;
//	return (1);
//}

t_ray	find_ray(t_scene *scene, int x, int y)
{
	t_tuple	direction;
	float	world_x;
	float	world_y;

	world_y = scene->half - y * scene->pixel_size;
	world_x = -scene->half + x * scene->pixel_size;
	direction = substract(point(world_x, world_y, scene->wall_z),
			scene->origin);
	direction = normalize(direction);
	return (ray(scene->origin, direction));
}

void	render_pixel(t_scene *scene, int x, int y)
{
	t_intersections	xs;
	t_intersection	h;
	t_shade			shade;
	t_ray			r;

	r = find_ray(scene, x, y);
	shade.m = scene->sphere.material;
	shade.light = scene->light;
	shade.eyev = negate(r.direction);
	xs = intersect(scene->sphere, r);
	if (xs.count == 0)
		return ;
	h = hit(xs);
	shade.p = position(r, h.t);
	shade.normalv = normal_at(scene->sphere, shade.p);
	write_pixel(&scene->canvas, x, y, lighting(shade));
	free(xs.intersections);
}

void	render_row(t_scene *scene, int y)
{
	int		x;

	x = 0;
	while (x < scene->canvas.width)
	{
		render_pixel(scene, x, y);
		x++;
	}
}

int	render_scene(t_scene *scene)
{
	int		y;

	y = 0;
	while (y < scene->canvas.height)
	{
		render_row(scene, y);
		y++;
	}
	return (1);
}

int	main(void)
{
	t_world			world;
	t_intersections	xs;
	t_ray			r;

	world = default_world();
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	xs = intersect_world(r, world);
	if (xs.err == true)
		return (free(world.spheres), 1);
	printf("%i\n", xs.count);
	int	i;

	i = 0;
	while (i < xs.count)
	{
		printf("%f\n", xs.intersections[i].t);
		i++;
	}
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
