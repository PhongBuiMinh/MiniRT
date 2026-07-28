/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 07:35:42 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/28 21:42:48 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	add_object(t_scene *scene, t_scene_obj obj)
{
	if (scene->obj_count >= MAX_OBJECTS)
		return (0);
	scene->objects[scene->obj_count++] = obj;
	return (1);
}

// Format: sp x,y,z diameter R,G,B
int	parse_sphere(char **tokens, t_scene *scene)
{
	t_scene_obj	obj;

	if (token_count(tokens) != 4)
		return (0);
	ft_bzero(&obj, sizeof(obj));
	if (!parse_tuple(tokens[1], &obj.pos))
		return (0);
	if (!is_valid_number(tokens[2]))
		return (0);
	obj.diameter = ft_atof(tokens[2]);
	if (obj.diameter <= 0.0)
		return (0);
	if (!parse_color(tokens[3], &obj.color))
		return (0);
	obj.type = OBJ_SPHERE;
	return (add_object(scene, obj));
}

// Format: pl x,y,z nx,ny,nz R,G,B
int	parse_plane(char **tokens, t_scene *scene)
{
	t_scene_obj	obj;

	if (token_count(tokens) != 4)
		return (0);
	ft_bzero(&obj, sizeof(obj));
	if (!parse_tuple(tokens[1], &obj.pos))
		return (0);
	if (!parse_tuple(tokens[2], &obj.orientation))
		return (0);
	if (!is_normalized_range(obj.orientation))
		return (0);
	normalize_tuple(&obj.orientation);
	if (!parse_color(tokens[3], &obj.color))
		return (0);
	obj.type = OBJ_PLANE;
	return (add_object(scene, obj));
}

// Format: cy x,y,z ax,ay,az diameter height R,G,B
int	parse_cylinder(char **tokens, t_scene *scene)
{
	t_scene_obj	obj;

	if (token_count(tokens) != 6)
		return (0);
	ft_bzero(&obj, sizeof(obj));
	if (!parse_tuple(tokens[1], &obj.pos))
		return (0);
	if (!parse_tuple(tokens[2], &obj.orientation))
		return (0);
	if (!is_normalized_range(obj.orientation))
		return (0);
	normalize_tuple(&obj.orientation);
	if (!is_valid_number(tokens[3]) || !is_valid_number(tokens[4]))
		return (0);
	obj.diameter = ft_atof(tokens[3]);
	obj.height = ft_atof(tokens[4]);
	if (obj.diameter <= 0.0 || obj.height <= 0.0)
		return (0);
	if (!parse_color(tokens[5], &obj.color))
		return (0);
	obj.type = OBJ_CYLINDER;
	return (add_object(scene, obj));
}
