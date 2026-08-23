/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:47 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 18:31:28 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_singlethread(t_canvas *canvas, t_camera *camera,
		t_world *world, bool *error)
{
	t_tuple	color;
	t_ray	ray;
	int		y;
	int		x;

	y = 0;
	while (y < camera->v_size)
	{
		x = 0;
		while (x < camera->h_size)
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray, error);
			write_pixel(canvas, x, y, color);
			x++;
		}
		y++;
	}
}

t_canvas	*render_scene(t_camera camera, t_world world)
{
	t_canvas	*canvas;
	bool		error;

	error = false;
	canvas = init_canvas(camera.h_size, camera.v_size);
	if (!canvas)
		return (NULL);
	if (MULTITHREADING)
		render_multithread(canvas, &camera, &world, &error);
	else
		render_singlethread(canvas, &camera, &world, &error);
	if (error)
		return (free_canvas(canvas), NULL);
	return (canvas);
}

//camera.reverse_transform = object space to world space transformation
t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	t_tuple		direction;
	double		world_x;
	double		world_y;

	world_x = camera->half_width - (x + 0.5) * camera->pixel_size;
	world_y = camera->half_height - (y + 0.5) * camera->pixel_size;
	direction = normalize(t_substract(
				m_apply(camera->reverse_transform, point(world_x, world_y, -1)),
				camera->origin));
	return (r_init(camera->origin, direction));
}

void	render_minirt(t_program *prog)
{
	t_canvas	*rendered;
	int			x;
	int			y;

	rendered = render_scene(prog->camera, prog->world);
	if (!rendered)
		fatal("render_scene failed", prog);
	init_mlx(prog);
	init_img(prog);
	y = 0;
	while (y < rendered->height)
	{
		x = 0;
		while (x < rendered->width)
		{
			mlx_put_pixel(prog->img, x, y,
				color_to_int(rendered->pixels[y][x]));
			x++;
		}
		y++;
	}
	free_canvas(rendered);
}
