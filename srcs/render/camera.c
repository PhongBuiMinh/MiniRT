/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:58:48 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 15:59:24 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_camera_values(t_camera *camera)
{
	double	half_view;
	double	aspect;

	half_view = tan(camera->fov / 2);
	aspect = (double)camera->h_size / (double)camera->v_size;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view / aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = camera->half_width * 2 / camera->h_size;
}

t_camera	camera_init(int h_size, int v_size, double fov)
{
	t_camera	camera;

	camera.h_size = h_size;
	camera.v_size = v_size;
	camera.fov = fov;
	camera.transform = init_id_matrix(4, 4);
	find_camera_values(&camera);
	return (camera);
}
