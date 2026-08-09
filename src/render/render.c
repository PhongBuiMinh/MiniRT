/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:47 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/09 22:30:21 by fbui-min         ###   ########.fr       */
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
			color = color_at(world, ray);
			write_pixel(canvas, x, y, color);
			x++;
		}
		y++;
	}
	return (canvas);
}

//check and fix error handling
t_tuple	color_at(t_world world, t_ray ray)
{
	t_intersections	xs;
	t_intersection	h;
	t_phong			phong;

	xs = world_intersect(world, ray);
	h = hit(xs);
	free(xs.intersections);
	if (hit_exists(h))
		phong = phong_computations(h, ray);
	else
		return (color(0, 0, 0));
	phong.in_shadow = is_shadowed(world, phong.over_point);
	phong.light = world.light;
	return (phong_lightning(phong));
}

//obj_to_world = object space to world space transformation

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

// PHONG -------------------------------------------------------------
int	clamp_channel(double v)
{
	if (v < 0.0)
		return (0);
	if (v > 1.0)
		return (255);
	return ((int)(v * 255.0));
}

int	color_to_int(t_tuple color)
{
	int	r;
	int	g;
	int	b;

	r = clamp_channel(color.x);
	g = clamp_channel(color.y);
	b = clamp_channel(color.z);
	return (r << 24 | g << 16 | b << 8 | 255);
}

// void	print_matrix(t_matrix *matrix)
// {
// 	int	row;
// 	int	col;

// 	printf("Matrix (%d x %d):\n", matrix->rows, matrix->cols);
// 	row = 0;
// 	while (row < matrix->rows)
// 	{
// 		col = 0;
// 		while (col < matrix->cols)
// 		{
// 			printf("%10.5f ", matrix->data[row][col]);
// 			col++;
// 		}
// 		printf("\n");
// 		row++;
// 	}
// }

// void	print_tuple(t_tuple *tuple)
// {
// 	printf("(%.5f, %.5f, %.5f, %.5f)",
// 		tuple->x,
// 		tuple->y,
// 		tuple->z,
// 		tuple->w);
// }

// void	print_light(t_light *light)
// {
// 	printf("\n========== LIGHT ==========\n");

// 	printf("intensity : ");
// 	print_tuple(&light->intensity);
// 	printf("\n");

// 	printf("position  : ");
// 	print_tuple(&light->pos);
// 	printf("\n");

// 	printf("===========================\n");
// }

// void	print_world(t_world *world)
// {
// 	int	i;

// 	printf("\n=========== WORLD ===========\n");

// 	printf("object_cnt : %d\n", world->object_cnt);

// 	printf("\nlight:\n");
// 	print_light(&world->light);

// 	printf("\nobjects : %p\n", (void *)world->objects);

// 	i = 0;
// 	while (i < world->object_cnt)
// 	{
// 		printf("objects[%d] : %p\n",
// 			i, (void *)world->objects[i]);
// 		i++;
// 	}

// 	printf("=============================\n");
// }

void	render_minirt(t_program *prog)
{
	t_canvas	*rendered;
	int			x;
	int			y;

	// printf("data after converting and building struct\n");
	// printf("========== CAMERA ==========\n");
	// printf("h_size     : %d\n", prog->camera.h_size);
	// printf("v_size     : %d\n", prog->camera.v_size);
	// printf("pixel_size : %f\n", prog->camera.pixel_size);
	// printf("half_width : %f\n", prog->camera.half_width);
	// printf("half_height: %f\n", prog->camera.half_height);
	// printf("fov        : %f\n", prog->camera.fov);
	// printf("\ntransform:\n");
	// print_matrix(&prog->camera.transform);
	// print_world(&prog->world);

	// printf("Starting render...\n");
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
			mlx_put_pixel(prog->mlx.img, x, y,
				color_to_int(rendered->pixels[y][x]));
			x++;
		}
		y++;
	}
}