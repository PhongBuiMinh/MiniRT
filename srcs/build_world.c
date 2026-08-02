/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:46:50 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/28 20:25:52 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "scene.h"

// typedef struct s_light
// {
// 	t_tuple	intensity;
// 	t_tuple	pos;
// }	t_light;

// static t_light	make_light(t_tuple position, t_color intensity)
// {
// 	t_light	light;

// 	light.pos = position;
// 	light.intensity = intensity;
// 	return (light);
// }

// static int	add_object(t_world *w, t_object *obj)
// {
// 	if (w->object_cnt >= WORLD_MAX_OBJECTS)
// 		return (0);
// 	w->objects[w->object_cnt++] = obj;
// 	return (1);
// }

// static t_object	*make_sphere_object(const t_scene_obj *src)
// {
// 	t_object	*obj;
// 	t_sphere	*s;
// 	t_matrix4	transform;
// 	double		r;

// 	obj = sphere_object_new();
// 	if (!obj)
// 		return (NULL);
// 	s = obj->shape.sphere;
// 	r = src->diameter / 2.0;
// 	transform = matrix4_mul(
// 			translation(src->pos.x, src->pos.y, src->pos.z),
// 			scaling(r, r, r));
// 	sphere_set_transform(s, transform);
// 	s->material.color = src->color;
// 	return (obj);
// }

// static t_object	*make_plane_object(const t_scene_obj *src)
// {
// 	t_object	*obj;
// 	t_plane		*p;

// 	obj = plane_object_new();
// 	if (!obj)
// 		return (NULL);
// 	p = obj->shape.plane;
// 	plane_set_position_and_normal(p, src->pos, src->orientation);
// 	p->material.color = src->color;
// 	return (obj);
// }

// static t_object	*make_cylinder_object(const t_scene_obj *src)
// {
// 	t_object	*obj;
// 	t_cylinder	*c;
// 	double		r;

// 	obj = cylinder_object_new();
// 	if (!obj)
// 		return (NULL);
// 	c = obj->shape.cylinder;
// 	r = src->diameter / 2.0;
// 	cylinder_set_axis_and_size(c, src->pos, src->orientation, r, src->height);
// 	c->material.color = src->color;
// 	return (obj);
// }

// static t_object	*make_object(const t_scene_obj *src)
// {
// 	if (src->type == OBJ_SPHERE)
// 		return (make_sphere_object(src));
// 	if (src->type == OBJ_PLANE)
// 		return (make_plane_object(src));
// 	if (src->type == OBJ_CYLINDER)
// 		return (make_cylinder_object(src));
// 	return (NULL);
// }

// static int	init_camera(t_camera *cam, const t_scene *s)
// {
// 	t_tuple	from;
// 	t_tuple	to;
// 	t_tuple	up;
// 	t_matrix4	view;

// 	*cam = camera_init(WIDTH, HEIGHT, s->cam_fov * M_PI / 180.0);
// 	from = point(s->cam_pos.x, s->cam_pos.y, s->cam_pos.z);
// 	to = add_tuple(from, vector(s->cam_dir.x, s->cam_dir.y, s->cam_dir.z));
// 	up = vector(0, 1, 0);
// 	view = view_transform(from, to, up);
// 	cam->transform = view;
// 	return (1);
// }

// static int	scene_ready(const t_scene *s)
// {
// 	if (!s)
// 		return (0);
// 	if (!s->has_ambient || !s->has_camera || !s->has_light)
// 		return (0);
// 	if (s->obj_count <= 0)
// 		return (0);
// 	return (1);
// }

int	build_world_from_scene(t_scene *s, t_world *w, t_camera *cam)
{
	// int		i;
	// t_tuple	light_pos;
	// t_color	light_color;

	// if (!scene_ready(s) || !w || !cam)
	// 	return (0);
	// ft_bzero(w, sizeof(*w));
	// light_pos = point(s->light_pos.x, s->light_pos.y, s->light_pos.z);
	// light_color = mul_color_scalar(s->light_color, s->light_brightness);
	// w->light = make_light(light_pos, light_color);
	// if (!init_camera(cam, s))
	// 	return (0);
	// i = 0;
	// while (i < s->obj_count)
	// {
	// 	t_object	*obj;

	// 	obj = make_object(&s->objects[i]);
	// 	if (!obj)
	// 		return (0);
	// 	if (!add_object(w, obj))
	// 		return (0);
	// 	i++;
	// }
	(void)s;
	(void)w;
	(void)cam;
	return (1);
}

// static int	create_sphere(t_world *w, const t_scene_obj *obj)
// {
// 	t_sphere	sp;
// 	t_matrix4	transform;
// 	double		radius;

// 	sp = sphere_new();
// 	transform = matrix4_identity();
// 	radius = obj->diameter / 2.0;
// 	transform = matrix4_mul(translation(obj->pos.x, obj->pos.y, obj->pos.z),
// 			scaling(radius, radius, radius));
// 	sphere_set_transform(&sp, transform);
// 	sp.material.color = obj->color;
// 	if (w->sphere_count >= MAX_SPHERES)
// 		return (0);
// 	w->spheres[w->sphere_count++] = sp;
// 	return (1);
// }

// static int	create_plane(t_world *w, const t_scene_obj *obj)
// {
// 	t_plane	pl;

// 	pl = plane_new();
// 	if (w->plane_count >= MAX_PLANES)
// 		return (0);
// 	plane_set_position_and_normal(&pl, obj->pos, obj->normal_or_axis);
// 	pl.material.color = obj->color;
// 	w->planes[w->plane_count++] = pl;
// 	return (1);
// }

// static int	create_cylinder(t_world *w, const t_scene_obj *obj)
// {
// 	t_cylinder	cy;
// 	double		radius;

// 	cy = cylinder_new();
// 	radius = obj->diameter / 2.0;
// 	if (w->cyl_count >= MAX_CYLINDERS)
// 		return (0);
// 	cylinder_set_axis_and_size(&cy, obj->pos, obj->normal_or_axis,
// 		radius, obj->height);
// 	cy.material.color = obj->color;
// 	w->cylinders[w->cyl_count++] = cy;
// 	return (1);
// }

// static int	setup_camera(t_camera *cam, const t_scene *s)
// {
// 	t_tuple		from;
// 	t_tuple		to;
// 	t_tuple		up;
// 	t_matrix4	view;

// 	cam->h_size = WIDTH;
// 	cam->v_size = HEIGHT;
// 	cam->field_of_view = s->cam_fov_deg * M_PI / 180.0;
// 	cam->transform = matrix4_identity();
// 	from = point(s->cam_pos.x, s->cam_pos.y, s->cam_pos.z);
// 	to = add_tuple(from, vector(s->cam_dir.x, s->cam_dir.y, s->cam_dir.z));
// 	up = vector(0, 1, 0);
// 	view = view_transform(from, to, up);
// 	camera_set_transform(cam, view);
// 	return (1);
// }

// int	validate_scene(const t_scene *s)
// {
// 	if (!s)
// 		return (0);
// 	if (!s->has_camera || !s->has_light || !s->has_ambient)
// 		return (0);
// 	return (1);
// }

// static int	process_object(t_world *w, const t_scene_obj *obj)
// {
// 	if (obj->type == OBJ_SPHERE)
// 		return (create_sphere(w, obj));
// 	if (obj->type == OBJ_PLANE)
// 		return (create_plane(w, obj));
// 	if (obj->type == OBJ_CYLINDER)
// 		return (create_cylinder(w, obj));
// 	return (1);
// }

// t_light point_light(t_tuple position, t_color intensity)
// {
// 	t_light	light;

// 	light.position = position;
// 	light.intensity = intensity;
// 	return (light);
// }

// int	build_world_from_scene(t_scene *s, t_world *w, t_camera *cam)
// {
// 	int		i;
// 	int		success;
// 	t_tuple	light_position;
// 	t_color	light_color_bright;

// 	if (!validate_scene(s) || !w || !cam)
// 		return (0);
// 	w->ambient_ratio = s->ambient_ratio;
// 	w->ambient_color = s->ambient_color;
// 	light_position = point(s->light_pos.x, s->light_pos.y, s->light_pos.z);
// 	light_color_bright = mul_color_scalar(s->light_color, s->light_brightness);
// 	w->light = point_light(light_position, light_color_bright);
// 	if (!setup_camera(cam, s))
// 		return (0);
// 	w->sphere_count = 0;
// 	w->plane_count = 0;
// 	w->cyl_count = 0;
// 	i = -1;
// 	while (++i < s->obj_count)
// 	{
// 		success = process_object(w, &s->objects[i]);
// 		if (!success)
// 			return (0);
// 	}
// 	return (1);
// }
