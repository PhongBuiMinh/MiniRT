/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:17:46 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 23:21:08 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "canvas.h"
# include "objects.h"
# include "light.h"

typedef struct s_scene
{
	t_canvas	canvas;
	t_tuple		origin;
	t_sphere	sphere;
	t_light		light;
	double		half;
	double		pixel_size;
	double		wall_z;
}	t_scene;

t_tuple	color_at(t_world world, t_ray ray);
int		render_scene(t_scene *scene);
void	render_pixel(t_scene *scene, int x, int y);

#endif