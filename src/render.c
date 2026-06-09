/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:47 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 23:22:12 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	find_direction(t_scene *scene, int x, int y)
{
	t_tuple	direction;
	float	world_x;
	float	world_y;

	world_y = scene->half - y * scene->pixel_size;
	world_x = -scene->half + x * scene->pixel_size;
	direction = t_substract(point(world_x, world_y, scene->wall_z),
			scene->origin);
	direction = normalize(direction);
	return (r_init(scene->origin, direction));
}


void	render_pixel(t_scene *scene, int x, int y)
{
	t_intersections	xs;
	t_intersection	is;
	t_phong			phong;
	t_ray			ray;

	ray = find_direction(scene, x, y);
	xs = xs_find(scene->sphere, ray);
	if (xs.count == 0)
	{
		free(xs.intersections);
		return ;
	}
	is = hit(xs);
	phong = phong_computations(is, ray);
	phong.light = scene->light;
	write_pixel(&scene->canvas, x, y, phong_lightning(phong));
	free(xs.intersections);
}

int	render_scene(t_scene *scene)
{
	int		y;
	int		x;

	y = 0;
	while (y < scene->canvas.height)
	{
		x = 0;
		while (x < scene->canvas.width)
		{
			render_pixel(scene, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

t_tuple	color_at(t_world world, t_ray ray)
{
	t_intersections	xs;
	t_phong			phong;

	xs = world_intersect(world, ray);
	if (xs.count > 0)
		phong = phong_computations(hit(xs), ray);
	else
		return (color(0, 0, 0));
	phong.light = world.light;
	return (phong_lightning(phong));
}
