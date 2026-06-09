/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:47 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 22:30:57 by bpetrovi         ###   ########.fr       */
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

t_phong	phong_computations(t_intersection is, t_ray ray)
{
	t_phong	phong;

	phong.inside_obj = false;
	phong.object = is.object;
	phong.point = r_pos(ray, is.t);
	phong.eyev = t_negate(ray.direction);
	phong.normalv = normal_at(is.object, phong.point);
	if (dot(phong.eyev, phong.normalv))
	{
		phong.inside_obj = true;
		phong.normalv = t_negate(phong.normalv);
	}
	return (phong);
}

void	render_pixel(t_scene *scene, int x, int y)
{
	t_intersections	xs;
	t_intersection	is;
	t_phong			shade;
	t_ray			ray;

	xs = xs_find(scene->sphere, ray);
	if (xs.count == 0)
		return ;
	is = xs_hit(xs);
	ray = find_direction(scene, x, y);
	shade.light = scene->light;
	write_pixel(&scene->canvas, x, y, phong_lightning(shade));
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
