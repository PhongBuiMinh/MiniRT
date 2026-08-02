/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:46:50 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/02 18:46:07 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "scene.h"

static int	scene_ready(const t_scene *s)
{
	if (!s)
		return (0);
	if (!s->has_ambient || !s->has_camera || !s->has_light)
		return (0);
	if (s->obj_count <= 0)
		return (0);
	return (1);
}

static int		build_ambient_light(const t_scene *s, t_world *w);
static int		build_camera(const t_scene *s, t_camera *cam);
static t_object	*make_sphere_object(const t_scene_obj *src);
static t_object	*make_plane_object(const t_scene_obj *src);
static t_object	*make_cylinder_object(const t_scene_obj *src);

static int	build_ambient_light(const t_scene *s, t_world *w)
{
	t_tuple	light_pos;
	t_color	light_color;

	if (!s || !w)
		return (0);
	w->ambient_ratio = s->ambient_ratio;
	w->ambient_color = s->ambient_color;
	light_pos = point(s->light_pos.x, s->light_pos.y, s->light_pos.z);
	light_color = mul_color_scalar(s->light_color, s->light_brightness);
	w->light = point_light(light_pos, light_color);
	return (1);
}

static t_object	*make_object(const t_scene_obj *src)
{
	if (src->type == OBJ_SPHERE)
		return (make_sphere_object(src));
	if (src->type == OBJ_PLANE)
		return (make_plane_object(src));
	if (src->type == OBJ_CYLINDER)
		return (make_cylinder_object(src));
	return (NULL);
}

int	world_add_object(t_world *w, t_object *obj)
{
	if (!w || !obj)
		return (0);
	if (w->object_cnt >= WORLD_MAX_OBJECTS)
		return (0);
	w->objects[w->object_cnt++] = obj;
	return (1);
}

int	build_world_from_scene(t_scene *s, t_world *w, t_camera *cam)
{
	int			i;
	t_object	*obj;

	if (!scene_ready(s) || !w || !cam)
		return (0);
	ft_bzero(w, sizeof(*w));
	if (!build_ambient_light(s, w))
		return (0);
	if (!build_camera(s, cam))
		return (0);
	i = 0;
	while (i < s->obj_count)
	{
		obj = make_object(&s->objects[i]);
		if (!obj || !world_add_object(w, obj))
			return (0);
		i++;
	}
	return (1);
}
