/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 07:35:42 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/09 16:40:33 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_object_color(t_object *obj, t_color color)
{
	// obj->material.color = tuple(color.r, color.g, color.b);
	obj->material.color = vector(color.r, color.g, color.b);
}

int parse_sphere(char **tokens, t_scene *scene)
{
	t_tuple		center;
	double		diameter;
	t_color		color;
	t_object	*obj;
	static int	next_id = 0;

	if (token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], &center))
		return (0);
	if (!is_valid_number(tokens[2]))
		return (0);
	diameter = ft_atof(tokens[2]);
	if (diameter <= 0.0)
		return (0);
	if (!parse_color(tokens[3], &color))
		return (0);

	obj = sphere_create(next_id++);
	if (!obj)
		return (0);

	// Scale = diameter/2, then translate
	t_matrix s = scaling(diameter / 2.0, diameter / 2.0, diameter / 2.0);
	t_matrix t = translation(center.x, center.y, center.z);
	t_matrix transform = m_multiply(t, s);  // adjust order to your convention

	set_transformation(obj, transform);
	set_object_color(obj, color);

	if (!scene_add_object(scene, obj))
		return (free(obj), 0);
	return (1);
}

int parse_plane(char **tokens, t_scene *scene)
{
	t_tuple		point;
	t_tuple		normal;
	t_color		color;
	t_object	*obj;
	static int	next_id = 0;

	if (token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], &point))
		return (0);
	if (!parse_tuple(tokens[2], &normal))
		return (0);
	if (!is_normalized_range(normal))
		return (0);
	normalize_tuple(&normal);
	if (!parse_color(tokens[3], &color))
		return (0);

	obj = plane_create(next_id++);
	if (!obj)
		return (0);

	// Build transform that maps canonical plane (y=0, normal (0,1,0)) to (point, normal)
	t_tuple new_y = normal;
	t_tuple new_z;
	t_tuple new_x;

	if (fabs(new_y.x) < 0.99)
		new_z = normalize(cross(new_y, vector(1, 0, 0)));
	else
		new_z = normalize(cross(new_y, vector(0, 0, 1)));

	new_x = cross(new_y, new_z);

	t_matrix rot = init_id_matrix(4, 4);
	rot.data[0][0] = new_x.x; rot.data[0][1] = new_x.y; rot.data[0][2] = new_x.z;
	rot.data[1][0] = new_y.x; rot.data[1][1] = new_y.y; rot.data[1][2] = new_y.z;
	rot.data[2][0] = new_z.x; rot.data[2][1] = new_z.y; rot.data[2][2] = new_z.z;

	t_matrix trans = translation(point.x, point.y, point.z);
	t_matrix transform = m_multiply(trans, rot);

	set_transformation(obj, transform);
	set_object_color(obj, color);

	if (!scene_add_object(scene, obj))
		return (free(obj), 0);
	return (1);
}

/* Format: cy x,y,z ax,ay,az diameter height R,G,B */
int	parse_cylinder(char **tokens, t_scene *scene)
{
	t_tuple		center;
	t_tuple		axis;
	double		diameter;
	double		height;
	t_color		color;
	t_object	*obj;
	static int	next_id = 0;

	if (token_count(tokens) != 6)
		return (0);
	if (!parse_tuple(tokens[1], &center))
		return (0);
	if (!parse_tuple(tokens[2], &axis))
		return (0);
	if (!is_normalized_range(axis))
		return (0);
	normalize_tuple(&axis);
	if (!is_valid_number(tokens[3]) || !is_valid_number(tokens[4]))
		return (0);
	diameter = ft_atof(tokens[3]);
	height = ft_atof(tokens[4]);
	if (diameter <= 0.0 || height <= 0.0)
		return (0);
	if (!parse_color(tokens[5], &color))
		return (0);

	obj = cylinder_create(next_id++);
	if (!obj)
		return (0);

	double radius = diameter / 2.0;

	// Build rotation from (0,1,0) to axis
	t_tuple new_y = axis;
	t_tuple new_z;
	t_tuple new_x;

	if (fabs(new_y.x) < 0.99)
		new_z = normalize(cross(new_y, vector(1, 0, 0)));
	else
		new_z = normalize(cross(new_y, vector(0, 0, 1)));

	new_x = cross(new_y, new_z);

	t_matrix rot = init_id_matrix(4, 4);
	rot.data[0][0] = new_x.x; rot.data[0][1] = new_x.y; rot.data[0][2] = new_x.z;
	rot.data[1][0] = new_y.x; rot.data[1][1] = new_y.y; rot.data[1][2] = new_y.z;
	rot.data[2][0] = new_z.x; rot.data[2][1] = new_z.y; rot.data[2][2] = new_z.z;

	t_matrix scale = scaling(radius, height, radius);
	t_matrix trans = translation(center.x, center.y, center.z);

	t_matrix transform = m_multiply(trans, m_multiply(rot, scale));

	set_transformation(obj, transform);
	set_object_color(obj, color);

	if (!scene_add_object(scene, obj))
		return (free(obj), 0);
	return (1);
}

// int	add_object(t_scene *scene, t_scene_obj obj)
// {
// 	if (scene->obj_count >= MAX_OBJECTS)
// 		return (0);
// 	scene->objects[scene->obj_count++] = obj;
// 	return (1);
// }

// // Format: sp x,y,z diameter R,G,B
// int	parse_sphere(char **tokens, t_scene *scene)
// {
// 	t_scene_obj	obj;

// 	if (token_count(tokens) != 4)
// 		return (0);
// 	ft_bzero(&obj, sizeof(obj));
// 	if (!parse_tuple(tokens[1], &obj.pos))
// 		return (0);
// 	if (!is_valid_number(tokens[2]))
// 		return (0);
// 	obj.diameter = ft_atof(tokens[2]);
// 	if (obj.diameter <= 0.0)
// 		return (0);
// 	if (!parse_color(tokens[3], &obj.color))
// 		return (0);
// 	obj.type = OBJ_SPHERE;
// 	return (add_object(scene, obj));
// }

// // Format: pl x,y,z nx,ny,nz R,G,B
// int	parse_plane(char **tokens, t_scene *scene)
// {
// 	t_scene_obj	obj;

// 	if (token_count(tokens) != 4)
// 		return (0);
// 	ft_bzero(&obj, sizeof(obj));
// 	if (!parse_tuple(tokens[1], &obj.pos))
// 		return (0);
// 	if (!parse_tuple(tokens[2], &obj.orientation))
// 		return (0);
// 	if (!is_normalized_range(obj.orientation))
// 		return (0);
// 	normalize_tuple(&obj.orientation);
// 	if (!parse_color(tokens[3], &obj.color))
// 		return (0);
// 	obj.type = OBJ_PLANE;
// 	return (add_object(scene, obj));
// }

// // Format: cy x,y,z ax,ay,az diameter height R,G,B
// int	parse_cylinder(char **tokens, t_scene *scene)
// {
// 	t_scene_obj	obj;

// 	if (token_count(tokens) != 6)
// 		return (0);
// 	ft_bzero(&obj, sizeof(obj));
// 	if (!parse_tuple(tokens[1], &obj.pos))
// 		return (0);
// 	if (!parse_tuple(tokens[2], &obj.orientation))
// 		return (0);
// 	if (!is_normalized_range(obj.orientation))
// 		return (0);
// 	normalize_tuple(&obj.orientation);
// 	if (!is_valid_number(tokens[3]) || !is_valid_number(tokens[4]))
// 		return (0);
// 	obj.diameter = ft_atof(tokens[3]);
// 	obj.height = ft_atof(tokens[4]);
// 	if (obj.diameter <= 0.0 || obj.height <= 0.0)
// 		return (0);
// 	if (!parse_color(tokens[5], &obj.color))
// 		return (0);
// 	obj.type = OBJ_CYLINDER;
// 	return (add_object(scene, obj));
// }
