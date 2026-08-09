/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:46:50 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/09 16:36:37 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	build_camera(const t_scene *s, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix	view;

	if (!s || !cam)
		return (0);
	*cam = camera_init(WIDTH, HEIGHT, s->cam_fov * M_PI / 180.0);
	from = point(s->cam_pos.x, s->cam_pos.y, s->cam_pos.z);
	to = t_add(from, vector(s->cam_dir.x, s->cam_dir.y, s->cam_dir.z));
	up = vector(0, 1, 0);
	view = view_transform(from, to, up);
	cam->transform = view;
	return (1);
}

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
