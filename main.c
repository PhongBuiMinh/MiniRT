/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/05 21:25:04 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_tuple color(float r, float g, float b)
{
	return (vector(r, g, b));
}

int	main(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;

	a = color(0.9, 0.6, 0.7);
	b = color(0.7, 0.1, 0.25);
	c = substract(a, b);
	print_tuple(c);
}
