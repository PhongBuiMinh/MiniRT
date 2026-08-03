/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:12:41 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/03 18:12:46 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:33:37 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/03 16:08:10 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	build_camera(const t_scene *s, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix4	view;

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

static t_object	*make_sphere_object(const t_scene_obj *src)
{
	t_object	*obj;
	t_sphere	*s;
	t_matrix4	transform;
	double		radius;

	if (!src)
		return (NULL);
	obj = sphere_object_new();
	if (!obj)
		return (NULL);
	s = obj->shape.sphere;
	radius = src->diameter / 2.0;
	transform = matrix4_mul(
			translation(src->pos.x, src->pos.y, src->pos.z),
			scaling(radius, radius, radius));
	sphere_set_transform(s, transform);
	s->material.color = src->color;
	return (obj);
}

static t_object	*make_plane_object(const t_scene_obj *src)
{
	t_object	*obj;
	t_plane		*p;

	if (!src)
		return (NULL);
	obj = plane_object_new();
	if (!obj)
		return (NULL);
	p = obj->shape.plane;
	plane_set_position_and_normal(p, src->pos, src->orientation);
	p->material.color = src->color;
	return (obj);
}

static t_object	*make_cylinder_object(const t_scene_obj *src)
{
	t_object	*obj;
	t_cylinder	*c;
	double		radius;

	if (!src)
		return (NULL);
	obj = cylinder_object_new();
	if (!obj)
		return (NULL);
	c = obj->shape.cylinder;
	radius = src->diameter / 2.0;
	cylinder_set_axis_and_size(c, src->pos, src->orientation,
		radius, src->height);
	c->material.color = src->color;
	return (obj);
}
