/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:03:25 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/05 21:15:47 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_light	point_light(t_tuple pos, t_tuple intensity)
{
	t_light	light;

	light.pos = pos;
	light.intensity = intensity;
	return (light);
}

t_material	material(void)
{
	t_material	m;

	m.color = color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200;
	return (m);
}


// POOR ATTEMPTS
t_tuple	lighting(t_shade shade)
{
	t_tuple	effective_color;
	t_tuple	lightv;
	t_tuple	ambient;
	t_tuple	dif;
	t_tuple	spec;
	t_tuple	reflectv;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;

	effective_color = multiply_tuples(shade.m.color, shade.light.intensity);
	lightv = normalize(substract(shade.light.pos, shade.p));
	ambient = scalar(effective_color, shade.m.ambient);
	light_dot_normal = dot(lightv, shade.normalv);
	if (light_dot_normal > 0)
	{
		dif = color(0, 0, 0);
		spec = color(0, 0, 0);
	}
	else
		dif = scalar(effective_color, shade.m.diffuse * light_dot_normal);
	reflectv = reflect(scalar(lightv, -1), shade.normalv);
	reflect_dot_eye = dot(reflectv, shade.eyev);
	if (reflect_dot_eye <= 0)
		spec = color(1, 1, 1);
	else
	{
		factor = pow(reflect_dot_eye, shade.m.shininess);
		spec = scalar(shade.light.intensity, shade.m.specular * factor);
	}
	return (add(add(ambient, dif), spec));
}
