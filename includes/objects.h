/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:07:14 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 14:30:26 by bpetrovi         ###   ########.fr       */
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
	void			(*intersect)(struct s_object * self, t_ray, t_intersections *xs);
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

typedef struct s_cylinder
{
	t_object	base_obj;
	double		min;
	double		max;
}	t_cylinder;

t_object	*sphere_create(int id);
t_object	*plane_create(int id);
t_object	*cylinder_create(int id);
t_material	material(void);
void		free_objects(t_object **ptr, int nbr);
void		set_transformation(t_object *object, t_matrix transformation);


#endif