/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/13 19:12:12 by bpetrovi         ###   ########.fr       */
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

//RAND NOT ALLOWED (JUST FOR TESTING)

int	randomize_matrix(t_matrix *matrix, int rows, int cols)
{
	int	y;
	int	x;

	x = 0;
	matrix->rows = rows;
	matrix->cols = cols;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			matrix->data[x][y] = rand() % 1349;
			y++;
		}
		x++;
	}
	return (1);
}

int	main(void)
{
	t_matrix	matrix_a;
	t_matrix	matrix_b;

	randomize_matrix(&matrix_a, 4, 4);
	print_matrix(matrix_a);
	printf("\n--------------------------------------\n");
	submatrix(&matrix_b, matrix_a, 3, 1);
	print_matrix(matrix_b);
	return (0);
}
