/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:28:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/09 17:25:07 by bpetrovi         ###   ########.fr       */
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
	t_projectile	projectile;
	t_environment	environment;
	t_canvas		canvas;
	int				x;
	int				y;

	init_canvas(&canvas, 1000, 500);
	projectile = init_projectile(point(0, 1, 0), multiply(normalize(vector(1, 1.8, 0)), 11.25));
	environment = init_environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));
	while (projectile.position.y > 0)
	{
		//printf("%f\n %f\n", projectile.position.y, projectile.position.x);
		tick(&environment, &projectile);
		x = (int)(projectile.position.x + 0.5);
		y = (int)(projectile.position.y + 0.5);
		y = canvas.height - y;
		write_pixel(&canvas, x, y, color(1, 0, 0));
	}
	canvas_to_ppm(&canvas);
	free_pixels(canvas.pixels);
	return (0);
}
