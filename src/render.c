/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:47 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 20:11:08 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*render_scene(t_camera camera, t_world world)
{
	t_canvas	*canvas;
	t_tuple		color;
	t_ray		ray;
	int			y;
	int			x;

	canvas = init_canvas(camera.h_size, camera.v_size);
	if (!canvas)
		return (NULL);
	y = 0;
	while (y < camera.v_size)
	{
		x = 0;
		while (x < camera.h_size)
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray); // COULD FAIL
			write_pixel(canvas, x, y, color);
			x++;
		}
		y++;
	}
	return (canvas);
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

t_ray	ray_for_pixel(t_camera camera, int x, int y)
{
	t_matrix	obj_to_world;
	t_tuple		origin;
	t_tuple		direction;
	double		world_x;
	double		world_y;

	world_x = camera.half_width - (x + 0.5) * camera.pixel_size;
	world_y = camera.half_height - (y + 0.5) * camera.pixel_size;
	obj_to_world = inversion(camera.transform);
	origin = m_apply(obj_to_world, point(0, 0, 0));
	direction = normalize(t_substract(
				m_apply(obj_to_world, point(world_x, world_y, -1)),
				origin));
	return (r_init(origin, direction));
}

void	find_camera_values(t_camera *camera)
{
	double	half_view;
	double	aspect;

	half_view = tan(camera->fov / 2);
	aspect = (double)camera->h_size / (double)camera->v_size;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view / aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = camera->half_width * 2 / camera->h_size;
}


t_camera	camera_init(int h_size, int v_size, double fov)
{
	t_camera	camera;

	camera.h_size = h_size;
	camera.v_size = v_size;
	camera.fov = fov;
	camera.transform = init_id_matrix(4, 4);
	find_camera_values(&camera);
	return (camera);
}

