/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/05 22:51:30 by bpetrovi         ###   ########.fr       */
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

	x = 10;
	y = 20;
	int	i = 0;
	int	d;
	canvas = malloc(y * sizeof(t_tuple *));
	while (i < y)
	{
		d = 0;
		canvas[i] = malloc(x * sizeof(t_tuple));
		while (d < x)
		{
			canvas[i][d] = color(0, 0, 0);
			d++;
		}
		i++;
	}
	i = 0;
	while (i < y)
	{
		d = 0;
		while (d < x)
		{
			printf("pixel at coordination y: %i, x: %i   ", i, d);
			print_tuple(canvas[i][d]);
			printf("\n");
			d++;
		}
		i++;
	}
}
