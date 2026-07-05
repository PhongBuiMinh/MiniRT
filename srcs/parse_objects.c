/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 07:35:42 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 13:51:25 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	add_object(t_scene *scene, t_scene_obj obj)
{
	if (scene->obj_count >= MAX_OBJECTS)
		return (0);
	scene->objects[scene->obj_count] = obj;
	scene->obj_count++;
	return (1);
}

// Format: sp x,y,z diameter R,G,B
int	parse_sphere(char **tokens, t_scene *scene)
{
	t_scene_obj	obj;
	t_tuple		pos;
	double		diameter;
	t_color		color;

	if (token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!is_valid_number(tokens[2]))
		return (0);
	diameter = ft_atof(tokens[2]);
	if (diameter <= 0.0)
		return (0);
	if (!parse_color(tokens[3], &color))
		return (0);
	obj.type = OBJ_SPHERE;
	obj.pos = pos;
	obj.diameter = diameter;
	obj.color = color;
	return (add_object(scene, obj));
}

// Format: pl x,y,z nx,ny,nz R,G,B
int	parse_plane(char **tokens, t_scene *scene)
{
	t_scene_obj	obj;
	t_tuple		pos;
	t_tuple		normal;
	t_color		color;

	if (token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!parse_tuple(tokens[2], &normal))
		return (0);
	normalize_tuple(&normal);
	if (!parse_color(tokens[3], &color))
		return (0);
	obj.type = OBJ_PLANE;
	obj.pos = pos;
	obj.orientation = normal;
	obj.color = color;
	return (add_object(scene, obj));
}

// Format: cy x,y,z ax,ay,az diameter height R,G,B
int	parse_cylinder(char **tokens, t_scene *scene)
{
	t_scene_obj	obj;
	t_tuple		pos;
	t_tuple		axis;
	double		diameter;
	double		height;
	t_color		color;

	if (token_count(tokens) != 6)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!parse_tuple(tokens[2], &axis))
		return (0);
	normalize_tuple(&axis);
	if (!is_valid_number(tokens[3]))
		return (0);
	diameter = ft_atof(tokens[3]);
	if (diameter <= 0.0)
		return (0);
	if (!is_valid_number(tokens[4]))
		return (0);
	height = ft_atof(tokens[4]);
	if (height <= 0.0)
		return (0);
	if (!parse_color(tokens[5], &color))
		return (0);
	obj.type = OBJ_CYLINDER;
	obj.pos = pos;
	obj.orientation = axis;
	obj.diameter = diameter;
	obj.height = height;
	obj.color = color;
	return (add_object(scene, obj));
}
