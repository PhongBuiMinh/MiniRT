/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/01 21:13:25 by bpetrovi         ###   ########.fr       */
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

//t_canvas	canvas;
//init_canvas(&canvas, 1000, 1000);
//canvas_to_ppm(&canvas);
int	main(void)
{
	t_sphere		s;
	t_canvas		canvas;
	t_intersections	xs;
	t_tuple			origin;
	int				y;
	double			half;
	double			wall_size;
	double			pixel_size;

	init_canvas(&canvas, 100, 100);
	y = 0;
	wall_size = 7;
	pixel_size = wall_size / canvas.width;
	half = wall_size / 2;
	origin = point(0, 0, -5);
	s = sphere(5);
	while (y < canvas.height)
	{
		int x = 0;
		double world_y = half - pixel_size * y;
		while (x < canvas.width)
		{
			double world_x = -half + pixel_size * x;
			t_tuple pos = point(world_x, world_y, 10);
			t_ray r = ray(origin, normalize(substract(pos, origin)));
			xs = intersect(s, r);
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
	return (0);
}
// 	const struct s_shear	
// params = {.xy = 0, .xz = 0, .yx = 0, .yz = 0, .zx = 0, .zy = 2};