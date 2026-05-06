/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/06 10:48:28 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	equal(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

t_projectile	init_projectile(t_tuple position, t_tuple velocity)
{
	t_projectile	projectile;

	projectile.position = position;
	projectile.velocity = velocity;
	normalize(&projectile.velocity);
	return (projectile);
}

t_environment	init_environment(t_tuple gravity, t_tuple wind)
{
	t_environment	environment;

	environment.gravity = gravity;
	environment.wind = wind;
	return (environment);
}

void	tick(t_environment environment, t_projectile projectile)
{
	projectile.position = add(projectile.position, projectile.velocity);
	projectile.velocity = add(projectile.velocity, add(environment.gravity, environment.wind));
}

int	main(void)
{
	int		x;
	int		y;
	t_tuple	**canvas;

	x = 0;
	y = 0;
	canvas = init_canvas(10, 20);
	while (canvas[y])
	{
		x = 0;
		while (x < 10)
		{
			printf("coordinates y: %i, x: %i ", y, x);
			print_tuple(canvas[y][x]);
			x++;
		}
		y++;
	}
	free_canvas(canvas);
}
