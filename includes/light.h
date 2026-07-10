/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:01:53 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:48:01 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "tuple.h"
# include "intersections.h"
# include "rays.h"

typedef struct s_light
{
	t_tuple	intensity;
	t_tuple	pos;
}	t_light;

typedef struct s_phong
{
	t_object	*object;
	t_light		light;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		over_point;
	bool		in_shadow;
	bool		inside_obj;
}	t_phong;

// ONLY MADE TO COMPLY WITH NORMINETTE, HENCE THE NAME

typedef struct s_phong_norm
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
}	t_phong_norm;

t_phong		phong_computations(t_intersection is, t_ray ray);
t_tuple		phong_lightning(t_phong phong);
t_light		light_init(t_tuple pos, t_tuple intensity);

#endif