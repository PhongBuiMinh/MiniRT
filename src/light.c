/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:03:25 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 12:19:21 by bpetrovi         ###   ########.fr       */
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


// POOR ATTEMPTS
t_tuple	phong_lightning(t_phong phong)
{
	t_tuple	effective_color;
	t_tuple	lightv;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	reflectv;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;

	effective_color = t_multiply(phong.object->material.color, phong.light.intensity);
	lightv = normalize(t_substract(phong.light.pos, phong.point));
	ambient = t_scale(effective_color, phong.object->material.ambient);
	light_dot_normal = dot(lightv, phong.normalv);
	if (light_dot_normal < 0)
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = t_scale(effective_color, phong.object->material.diffuse * light_dot_normal);
		reflectv = reflect(t_scale(lightv, -1), phong.normalv);
		reflect_dot_eye = dot(reflectv, phong.eyev);
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, phong.object->material.shininess);
			specular = t_scale(phong.light.intensity, phong.object->material.specular * factor);
		}
	}
	if (phong.in_shadow)
		return (ambient);
	return (t_add(specular, t_add(diffuse, ambient)));
}
