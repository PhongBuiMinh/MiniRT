/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 07:35:42 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 03:02:16 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// out order: diameter height rgb
static int	validate_cylinder(char **tokens, t_tuple *center,
				t_tuple *axis, double out[5])
{
	t_color	color;

	if (token_count(tokens) != 6)
		return (0);
	if (!parse_tuple(tokens[1], center))
		return (0);
	if (!parse_tuple(tokens[2], axis))
		return (0);
	if (!is_valid_direction(axis))
		return (0);
	if (!is_valid_number(tokens[3]) || !is_valid_number(tokens[4]))
		return (0);
	out[0] = ft_atof(tokens[3]);
	out[1] = ft_atof(tokens[4]);
	if (out[0] <= 0.0 || out[1] <= 0.0)
		return (0);
	if (!parse_color(tokens[5], &color))
		return (0);
	out[2] = color.r;
	out[3] = color.g;
	out[4] = color.b;
	return (1);
}

static int	build_cylinder(const t_tuple *center, const t_tuple *axis,
						const double data[5], t_scene *scene)
{
	t_cylinder	*cy;
	t_matrix	transform;
	t_color		color;
	double		radius;

	cy = (t_cylinder *)cylinder_create(0);
	if (!cy)
		return (0);
	radius = data[0] / 2.0;
	cy->min = -data[1] / 2.0;
	cy->max = data[1] / 2.0;
	cy->closed = true;
	color.r = data[2];
	color.g = data[3];
	color.b = data[4];
	transform = m_multiply(
		translation(center->x, center->y, center->z),
		m_multiply(
			build_rotation_from_y(axis),
			scaling(radius, 1.0, radius)));
	set_transformation((t_object *)cy, transform);
	set_object_color((t_object *)cy, color);
	if (!scene_add_object(scene, (t_object *)cy))
		return (free(cy), 0);
	return (1);
}

// cy <center_x,center_y,center_z> <axis_x,axis_y,axis_z> <diameter> <height> <r,g,b>
int	parse_cylinder(char **tokens, t_scene *scene)
{
	t_tuple	center;
	t_tuple	axis;
	double	data[5];

	if (!validate_cylinder(tokens, &center, &axis, data))
		return (0);
	return (build_cylinder(&center, &axis, data, scene));
}
