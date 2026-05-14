/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/13 19:58:29 by bpetrovi         ###   ########.fr       */
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

	matrix_a = randomize_matrix(3, 3);
	print_matrix(matrix_a);
	printf("\n--------------------------------------\n");
	printf("minor: %f", minor(matrix_a, 1, 0));
	return (0);
}
