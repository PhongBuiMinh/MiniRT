/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:03:25 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:54:25 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	point_light(t_tuple pos, t_tuple intensity)
{
	t_light	light;

	light.pos = pos;
	light.intensity = intensity;
	return (light);
}

// POOR ATTEMPTS
t_tuple	lighting(t_shade shade)
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

	effective_color = t_multiply(shade.m.color, shade.light.intensity);
	lightv = normalize(t_substract(shade.light.pos, shade.p));
	ambient = t_scale(effective_color, shade.m.ambient);
	light_dot_normal = dot(lightv, shade.normalv);
	if (light_dot_normal < 0)
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = t_scale(effective_color, shade.m.diffuse * light_dot_normal);
		reflectv = reflect(t_scale(lightv, -1), shade.normalv);
		reflect_dot_eye = dot(reflectv, shade.eyev);
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, shade.m.shininess);
			specular = t_scale(shade.light.intensity, shade.m.specular * factor);
		}
	}
	return (t_add(specular, t_add(diffuse, ambient)));
}
