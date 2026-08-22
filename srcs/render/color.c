/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:00:07 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/22 17:37:56 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	color(double r, double g, double b)
{
	return ((t_tuple){.x = r, .y = g, .z = b, .w = 0});
}

int	clamp_color(int c)
{
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}

int	scale_color(float c)
{
	return (clamp_color((int)round(c * 255)));
}

int	color_to_int(t_tuple color)
{
	int	r;
	int	g;
	int	b;

	r = scale_color((float)color.x);
	g = scale_color((float)color.y);
	b = scale_color((float)color.z);
	return (r << 24 | g << 16 | b << 8 | 255);
}

//check and fix error handling
t_tuple	color_at(t_world world, t_ray ray)
{
	t_intersections	xs;
	t_intersection	h;
	t_phong			phong;

	xs = world_intersect(world, ray);
	h = hit(xs);
	free(xs.intersections);
	if (hit_exists(h))
		phong = phong_computations(h, ray);
	else
		return (color(0, 0, 0));
	phong.in_shadow = is_shadowed(world, phong.over_point);
	phong.light = world.light;
	phong.ambient = world.ambient;
	return (phong_lightning(phong));
}
