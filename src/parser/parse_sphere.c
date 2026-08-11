/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:51:09 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/11 15:35:35 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	build_sphere(const t_tuple *center, double radius,
				const t_color *color, t_scene *scene)
{
	t_object	*obj;
	t_matrix	scale;
	t_matrix	translate;
	t_matrix	transform;

	obj = sphere_create(0);
	if (!obj)
		return (0);
	scale = scaling(radius, radius, radius);
	translate = translation(center->x, center->y, center->z);
	transform = m_multiply(translate, scale);
	set_transformation(obj, transform);
	set_object_color(obj, *color);
	if (!scene_add_object(scene, obj))
		return (free(obj), 0);
	return (1);
}

static int	validate_sphere(char **tokens, t_tuple *center,
				double *radius, t_color *color)
{
	double	diameter;

	if (token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], center))
		return (0);
	if (!is_valid_number(tokens[2]))
		return (0);
	diameter = ft_atof(tokens[2]);
	if (diameter <= 0.0)
		return (0);
	*radius = diameter / 2.0;
	if (!parse_color(tokens[3], color))
		return (0);
	return (1);
}

// sp <center_x,center_y,center_z> <diameter> <r,g,b>
int	parse_sphere(char **tokens, t_scene *scene)
{
	t_tuple		center;
	double		radius;
	t_color		color;

	if (!validate_sphere(tokens, &center, &radius, &color))
		return (0);
	return (build_sphere(&center, radius, &color, scene));
}

// static int	build_sphere(const t_tuple *center, double radius,
// 				const t_color *color, t_scene *scene)
// {
// 	t_object	*obj;
// 	t_matrix	scale;
// 	t_matrix	translate;
// 	t_matrix	transform;
// 	static int	next_id = 0;

// 	obj = sphere_create(next_id++);
// 	obj = sphere_create(0);
// 	if (!obj)
// 		return (0);

// 	scale = scaling(radius, radius, radius);
// 	translate = translation(center->x, center->y, center->z);
// 	transform = m_multiply(translate, scale);
// 	set_transformation(obj, transform);
// 	set_object_color(obj, *color);
// 	if (!scene_add_object(scene, obj))
// 		return (free(obj), 0);
// 	return (1);
// }
