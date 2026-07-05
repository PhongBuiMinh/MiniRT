/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:07:14 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/03 22:43:34 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "matrices.h"

typedef struct s_intersections	t_intersections;

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_object
{
	t_tuple			(*normal_at)(t_tuple);
	t_intersections	(*intersect)(t_object * self, t_ray);
	t_matrix		transformation;
	t_material		material;
	int				id;
}	t_object;

typedef struct s_sphere
{
	t_object	base_obj;
}	t_sphere;

typedef struct s_plane
{
	t_object	base_obj;
}	t_plane;

typedef struct s_cone
{
	t_object	base_obj;
	double		radius;
	double		more_info;
}	t_cone;

t_object	*init_objects(int obj_cnt);
t_object	sphere(int id);
t_material	material(void);
void		set_transformation(t_object *object, t_matrix transformation);
void		set_as_sphere(t_object *object);


#endif