/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:46:50 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/09 15:16:27 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	build_world_from_scene(const t_scene *scene, t_world *world, t_camera *camera)
{
	if (!scene || !world || !camera)
		return (0);

	if (!scene->has_ambient || !scene->has_camera
		|| !scene->has_light || scene->object_cnt <= 0)
		return (0);
	world->light.pos = scene->pos;
	world->light.intensity = scene->intensity;
	world->objects = scene->objects;
	world->object_cnt = scene->object_cnt;
	if (!build_camera(scene, camera))
		return (0);
	return (1);
}
