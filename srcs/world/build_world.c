/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:46:50 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 18:20:24 by bpetrovi         ###   ########.fr       */
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
	*cam = camera_init(WIDTH, HEIGHT, s->cam_fov * PI / 180.0);
	from = point(s->cam_pos.x, s->cam_pos.y, s->cam_pos.z);
	to = t_add(from, vector(s->cam_dir.x, s->cam_dir.y, s->cam_dir.z));
	up = vector(0, 1, 0);
	if (fabs(s->cam_dir.y) > 0.999)
		up = vector(0, 0, 1);
	view = view_transform(from, to, up);
	cam->transform = view;
	cam->reverse_transform = inversion(view);
	cam->origin = m_apply(cam->reverse_transform, point(0, 0, 0));
	return (1);
}

int	build_world_from_scene(const t_scene *scene,
	t_world *world, t_camera *camera)
{
	if (!scene || !world || !camera)
		return (0);
	if (!scene->has_ambient || !scene->has_camera
		|| !scene->has_light || scene->object_cnt <= 0)
		return (0);
	world->light.pos = scene->pos;
	world->light.intensity = scene->intensity;
	world->ambient.color = color(
			scene->ambient_color.r,
			scene->ambient_color.g,
			scene->ambient_color.b);
	world->ambient.ratio = scene->ambient_ratio;
	world->objects = scene->objects;
	world->object_cnt = scene->object_cnt;
	if (!build_camera(scene, camera))
		return (0);
	return (1);
}

// int	build_world_from_scene(const t_scene *scene,
// 	t_world *world, t_camera *camera)
// {
// 	if (!scene || !world || !camera)
// 		return (0);

// 	/* Basic required flags */
// 	if (!scene->has_ambient || !scene->has_camera
// 	|| !scene->has_light || scene->object_cnt <= 0)
// 		return (0);

// 	/* FOV sanity check */
// 	if (scene->cam_fov <= 0.0 || scene->cam_fov >= 180.0)
// 		return (0);

// 	/* Convert / copy data from scene to world & camera */
// 	world->light.pos = scene->pos;
// 	world->light.intensity = scene->intensity;
// 	world->objects = scene->objects;
// 	world->object_cnt = scene->object_cnt;

// 	if (!build_camera(scene, camera))
// 		return (0);

// 	/* === PRINT EVERYTHING THAT WAS CONVERTED / PUSHED === */
// 	printf("\n========== BUILD_WORLD_FROM_SCENE: DATA DUMP ==========\n");

// 	/* --- World --- */
// 	printf("WORLD:\n");
// 	printf("  object_cnt       : %d\n", world->object_cnt);

// 	printf("  light.pos        : (%.6f, %.6f, %.6f)\n",
// 		world->light.pos.x, world->light.pos.y, world->light.pos.z);
// 	printf("  light.intensity  : (%.6f, %.6f, %.6f)\n",
// 		world->light.intensity.x, world->light.intensity.y,
// 		world->light.intensity.z);

// 	printf("  objects array    : %p\n", (void *)world->objects);
// 	for (int i = 0; i < world->object_cnt; i++)
// 	{
// 		t_object *obj = world->objects[i];
// 		printf("  objects[%d]      : %p\n", i, (void *)obj);
// 		if (!obj)
// 			continue;

// 		printf("    id             : %d\n", obj->id);
// 		printf("    material:\n");
// 		printf("      color        : (%.6f, %.6f, %.6f)\n",
// 			obj->material.color.x,
// 			obj->material.color.y,
// 			obj->material.color.z);
// 		printf("      ambient      : %.6f\n", obj->material.ambient);
// 		printf("      diffuse      : %.6f\n", obj->material.diffuse);
// 		printf("      specular     : %.6f\n", obj->material.specular);
// 		printf("      shininess    : %.6f\n", obj->material.shininess);

// 		printf("    transformation (%dx%d):\n",
// 			obj->transformation.rows, obj->transformation.cols);
// 		for (int r = 0; r < obj->transformation.rows; r++)
// 		{
// 			printf("      ");
// 			for (int c = 0; c < obj->transformation.cols; c++)
// 				printf("%12.6f ", obj->transformation.data[r][c]);
// 			printf("\n");
// 		}
// 	}

// 	/* --- Camera --- */
// 	printf("\nCAMERA:\n");
// 	printf("  h_size           : %d\n", camera->h_size);
// 	printf("  v_size           : %d\n", camera->v_size);
// 	printf("  fov (deg)        : %.6f\n", scene->cam_fov);
// 	printf("  fov (rad)        : %.6f\n", camera->fov);
// 	printf("  pixel_size       : %.10f\n", camera->pixel_size);
// 	printf("  half_width       : %.10f\n", camera->half_width);
// 	printf("  half_height      : %.10f\n", camera->half_height);

// 	printf("  transform (4x4):\n");
// 	for (int r = 0; r < 4; r++)
// 	{
// 		printf("    ");
// 		for (int c = 0; c < 4; c++)
// 			printf("%12.6f ", camera->transform.data[r][c]);
// 		printf("\n");
// 	}

// 	printf("========================================================\n\n");

// 	return (1);
// }
