/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:06:50 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/05 21:07:01 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "lighting.h"

typedef struct s_light_calc
{
	t_color effective_color;
	t_tuple lightv;
	double  light_dot_normal;
	t_tuple reflectv;
	double  reflect_dot_eye;
	double  factor;
}	t_light_calc;

t_color	lighting(t_light_params p)
{
	t_light_calc	c;
	t_color			ambient;
	t_color			diffuse;
	t_color			specular;

	c.effective_color = hadamard_color(p.material.color, p.light.intensity);
	ambient = mul_color_scalar(c.effective_color, p.material.ambient);
	if (p.in_shadow)
		return (ambient);
	c.lightv = normalize(sub_tuple(p.light.position, p.point_pos));
	c.light_dot_normal = dot(c.lightv, p.normalv);
	if (c.light_dot_normal < 0.0)
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = mul_color_scalar(c.effective_color,
					p.material.diffuse * c.light_dot_normal);
		c.reflectv = negate_tuple(sub_tuple(
						c.lightv,
						mul_tuple_scalar(p.normalv, 2.0 * c.light_dot_normal)));
		c.reflect_dot_eye = dot(c.reflectv, p.eyev);
		if (c.reflect_dot_eye <= 0.0)
			specular = color(0, 0, 0);
		else
		{
			c.factor = pow(c.reflect_dot_eye, p.material.shininess);
			specular = mul_color_scalar(p.light.intensity,
						p.material.specular * c.factor);
		}
	}
	return (add_color(add_color(ambient, diffuse), specular));
}
