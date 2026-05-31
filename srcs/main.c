/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/31 18:42:08 by bpetrovi         ###   ########.fr       */
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
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_sphere		s = sphere(5);
	t_intersections	xs;

	xs = intersect(s, r);
	printf("xs count: %i, t1: %f, t2; %f2, t1 object: %i, t2 object: %i\n", xs.count, xs.intersections[0].t, xs.intersections[1].t, xs.intersections[0].object, xs.intersections[1].object);
}
// 	const struct s_shear	
// params = {.xy = 0, .xz = 0, .yx = 0, .yz = 0, .zx = 0, .zy = 2};