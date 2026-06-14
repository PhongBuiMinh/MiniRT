/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:19:43 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/13 18:47:01 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tuple.h"
#include "color.h"

typedef struct s_projectile
{
	t_tuple	position;  // point
	t_tuple	velocity;  // vector
}	t_projectile;

typedef struct s_environment
{
	t_tuple	gravity;   // vector
	t_tuple	wind;      // vector
}	t_environment;

t_projectile	tick(t_environment env, t_projectile proj)
{
	t_projectile	next;

	next.position = add_tuple(proj.position, proj.velocity);
	next.velocity = add_tuple(add_tuple(proj.velocity, env.gravity), env.wind);
	return (next);
}

int main(void)
{
	int				width = 900;
	int				height = 550;
	t_canvas		canvas;
	t_color			red = color(1, 0, 0);
	t_projectile	proj;
	t_environment	env;
	int				steps = 0;

	canvas = canvas_new(width, height);
	if (!canvas.pixels)
		return (1);
	proj.position = point(0, 1, 0);
	proj.velocity = vector(1, 1.8, 0);
	proj.velocity = normalize(proj.velocity);
	proj.velocity = mul_tuple_scalar(proj.velocity, 11.25);
	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);
	while (proj.position.y > 0.0)
	{
		int x = (int)(proj.position.x + 0.5);
		int y = height - 1 - (int)(proj.position.y + 0.5);
		if (x >= 0 && x < width && y >= 0 && y < height)
			write_pixel(&canvas, x, y, red);
		proj = tick(env, proj);
		steps++;
		if (steps > 10000)
			break;
	}
	canvas_to_ppm(&canvas, "projectile.ppm");
	canvas_destroy(&canvas);
	printf("Wrote projectile.ppm\n");
	return (0);
}
