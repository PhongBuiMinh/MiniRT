/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/14 20:47:59 by bpetrovi         ###   ########.fr       */
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
	t_matrix	matrix_a;

	matrix_a = parse_matrix("| 3 | -9 | 7 | 3 || 3 | -8 | 2 | -9 || -4 | 4 | 4 | 1 | -6 | 5 | -1 | 1 |", 4, 4);
	print_matrix(transpose_matrix(inversion(matrix_a)));
	printf("-----------------------------------\n");
	print_matrix(inversion(transpose_matrix(matrix_a)));
}
