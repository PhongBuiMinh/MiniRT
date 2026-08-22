/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:17:46 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/22 18:02:48 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "canvas.h"
# include "objects.h"
# include "light.h"
# include "world.h"

typedef struct s_camera
{
	t_matrix	transform;
	t_matrix	reverse_transform;
	t_tuple		origin;
	int			h_size;
	int			v_size;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		fov;
}	t_camera;

t_camera	camera_init(int h_size, int v_size, double fov);
t_ray		ray_for_pixel(t_camera camera, int x, int y);
t_tuple		color_at(t_world world, t_ray ray);
t_canvas	*render_scene(t_camera camera, t_world world);

#endif