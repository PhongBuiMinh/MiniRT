/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/04 21:22:18 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_projectile	init_projectile(t_tuple position, t_tuple velocity)
{
	t_projectile	projectile;

	projectile.position = position;
	projectile.velocity = velocity;
	return (projectile);
}

t_environment	init_environment(t_tuple gravity, t_tuple wind)
{
	t_environment	environment;

	environment.gravity = gravity;
	environment.wind = wind;
	return (environment);
}

void	tick(t_environment *environment, t_projectile *projectile)
{
	projectile->position = add(projectile->position, projectile->velocity);
	projectile->velocity = add(projectile->velocity, add(environment->gravity, environment->wind));
}

// FUNCTION FOR FILLING MATRICES FOR TESTING

t_matrix	parse_matrix(char *str, int rows, int cols)
{
	t_matrix	matrix;
	int			x;
	int			y;

	matrix.rows = rows;
	matrix.cols = cols;

	x = 0;
	y = 0;
	while (*str && x < rows)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
		{
			matrix.data[x][y] = atof(str);

			while ((*str >= '0' && *str <= '9')
				|| *str == '-'
				|| *str == '.')
				str++;

			y++;
			if (y >= cols)
			{
				y = 0;
				x++;
			}
		}
		else
			str++;
	}

	return (matrix);
}

//RAND NOT ALLOWED (JUST FOR TESTING)

t_matrix	randomize_matrix(int rows, int cols)
{
	t_matrix	randomized_matrix;
	int			y;
	int			x;

	x = 0;
	randomized_matrix.rows = rows;
	randomized_matrix.cols = cols;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			randomized_matrix.data[x][y] = rand() % 1349;
			y++;
		}
		x++;
	}
	return (randomized_matrix);
}

int	main(void)
{
	t_light		light;
	t_sphere	s;

	s = sphere(5);
	print_tuple(s.material.color);
	light = point_light(point(0, 0, 0), color(1, 1, 1));
	print_tuple(light.pos);
	print_tuple(light.intensity);
	return (0);
}
/*
DRAWING A SPHERE BY CASTING RAYS AT IT
int	main(void)
{
	t_canvas		canvas;
	t_sphere		s;
	t_tuple			origin;
	t_tuple			position;
	t_intersections	xs;
	int				x;
	int				y;
	double			wall_size;
	double			world_x;
	double			world_y;
	double			half;
	double			pixel_size;

	wall_size = 10;
	origin = point(0, 0, -5);
	half = wall_size / 2;
	init_canvas(&canvas, 200, 200);
	pixel_size = wall_size / canvas.height;
	s = sphere(5);
	struct s_shear shear = {1, 0, 0, 0, 0, 0};
	s.transformation = multiply_matrices(shearing(shear), rotation_z(PI / 4));
	y = 0;
	while (y < canvas.height)
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < canvas.width)
		{
			world_x = -half + pixel_size * x;
			position = point(world_x, world_y, 10);
			xs = intersect(s, ray(origin, normalize(substract(position, origin))));
			if (xs.count != 0)
				write_pixel(&canvas, x, y, color(1, 0, 0));
			else
				write_pixel(&canvas, x, y, color(0, 0, 0));
			x++;
		}
		y++;
	}
	canvas_to_ppm(&canvas);
	free_pixels(canvas.pixels);
}
*/