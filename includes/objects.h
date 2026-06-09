/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:07:14 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:55:23 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "matrices.h"

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_sphere
{
	t_matrix	transformation;
	t_material	material;
	int			id;
}	t_sphere;

t_sphere	sphere(int id);
t_material	material(void);
void		set_transformation(t_sphere *sphere, t_matrix transformation);


#endif