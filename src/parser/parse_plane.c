/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:04:32 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/11 15:34:45 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_plane(char **tokens, t_tuple *point,
				t_tuple *normal, t_color *color)
{
	if (token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], point))
		return (0);
	if (!parse_tuple(tokens[2], normal))
		return (0);
	if (!is_normalized_range(*normal))
		return (0);
	normalize_tuple(normal);
	if (!parse_color(tokens[3], color))
		return (0);
	return (1);
}

static int	build_plane(const t_tuple *point, const t_tuple *normal,
			const t_color *color, t_scene *scene)
{
	t_object	*obj;
	t_matrix	rot;
	t_matrix	trans;
	t_matrix	transform;

	obj = plane_create(0);
	if (!obj)
		return (0);
	rot = build_rotation_from_y(normal);
	trans = translation(point->x, point->y, point->z);
	transform = m_multiply(trans, rot);
	set_transformation(obj, transform);
	set_object_color(obj, *color);
	if (!scene_add_object(scene, obj))
		return (free(obj), 0);
	return (1);
}

// pl <point_x,point_y,point_z> <normal_x,normal_y,normal_z> <r,g,b>
int	parse_plane(char **tokens, t_scene *scene)
{
	t_tuple		point;
	t_tuple		normal;
	t_color		color;

	if (!validate_plane(tokens, &point, &normal, &color))
		return (0);
	return (build_plane(&point, &normal, &color, scene));
}
