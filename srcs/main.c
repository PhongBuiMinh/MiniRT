/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/11 21:38:27 by bpetrovi         ###   ########.fr       */
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

int	main(void)
{
	t_matrix	matrix_a;
	t_matrix	matrix_b;

	init_matrix(&matrix_a, 4, 4);
	int	i = 0;
	while (i < 4)
	{
		int	a = 0;
		while (a < 4)
		{
			set_matrix(&matrix_a, i, a, i + a);
			a++;
		}
		i++;
	}
	print_matrix(matrix_a);
	printf("\n--------------------------------------------------------------\n");
	ind_matrix(&matrix_b, matrix_a);
	print_matrix(matrix_b);
	return (0);
}
