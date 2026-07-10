/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:03:25 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:32:45 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	light_init(t_tuple pos, t_tuple intensity)
{
	t_light	light;

	light.pos = pos;
	light.intensity = intensity;
	return (light);
}

t_phong	phong_computations(t_intersection is, t_ray ray)
{
	t_phong	phong;

	phong.in_shadow = false;
	phong.inside_obj = false;
	phong.object = is.object;
	phong.point = r_pos(ray, is.t);
	phong.eyev = t_negate(ray.direction);
	phong.normalv = normal_at(is.object, phong.point);
	if (dot(phong.eyev, phong.normalv) < 0)
	{
		phong.inside_obj = true;
		phong.normalv = t_negate(phong.normalv);
	}
	phong.over_point = t_add(phong.point, t_scale(phong.normalv, EPSILON));
	return (phong);
}

static void	calc_diffuse_specular(t_phong phong, t_phong_norm *norm)
{
	norm->diffuse = t_scale(norm->effective_color,
			phong.object->material.diffuse * norm->light_dot_normal);
	norm->reflectv = reflect(t_scale(norm->lightv, -1), phong.normalv);
	norm->reflect_dot_eye = dot(norm->reflectv, phong.eyev);
	if (norm->reflect_dot_eye <= 0)
		norm->specular = color(0, 0, 0);
	else
	{
		norm->factor = pow(norm->reflect_dot_eye,
				phong.object->material.shininess);
		norm->specular = t_scale(phong.light.intensity,
				phong.object->material.specular * norm->factor);
	}
}

static void	init_phong_norm(t_phong phong, t_phong_norm *norm)
{
	norm->effective_color = t_multiply(phong.object->material.color,
			phong.light.intensity);
	norm->lightv = normalize(t_substract(phong.light.pos, phong.point));
	norm->ambient = t_scale(norm->effective_color,
			phong.object->material.ambient);
	norm->light_dot_normal = dot(norm->lightv, phong.normalv);
}

t_tuple	phong_lightning(t_phong phong)
{
	t_phong_norm	norm;

	init_phong_norm(phong, &norm);
	if (norm.light_dot_normal < 0)
	{
		norm.diffuse = color(0, 0, 0);
		norm.specular = color(0, 0, 0);
	}
	else
		calc_diffuse_specular(phong, &norm);
	if (phong.in_shadow)
		return (norm.ambient);
	return (t_add(norm.specular, t_add(norm.diffuse, norm.ambient)));
}
