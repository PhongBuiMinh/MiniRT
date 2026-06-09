/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:23:47 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:30:03 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_pixel(t_scene *scene, int x, int y)
{
	t_intersections	xs;
	t_intersection	h;
	t_shade			shade;
	t_ray			r;

	r = r_find(scene, x, y);
	shade.m = scene->sphere.material;
	shade.light = scene->light;
	shade.eyev = t_negate(r.direction);
	xs = xs_find(scene->sphere, r);
	if (xs.count == 0)
		return ;
	h = xs_hit(xs);
	shade.p = r_pos(r, h.t);
	shade.normalv = normal_at(scene->sphere, shade.p);
	write_pixel(&scene->canvas, x, y, l_find(shade));
	free(xs.intersections);
}

void	render_row(t_scene *scene, int y)
{
	int		x;

	x = 0;
	while (x < scene->canvas.width)
	{
		render_pixel(scene, x, y);
		x++;
	}
}

int	render_scene(t_scene *scene)
{
	int		y;

	y = 0;
	while (y < scene->canvas.height)
	{
		render_row(scene, y);
		y++;
	}
	return (1);
}
