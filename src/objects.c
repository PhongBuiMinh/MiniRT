/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:04:12 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/03 22:29:47 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	set_transformation(t_object *object, t_matrix transformation)
{
	object->transformation = transformation;
}

t_object	object(int id)
{
	t_object	new_object;

	new_object.transformation = init_id_matrix(4, 4);
	new_object.material = material();
	new_object.id = id;
	return (new_object);
}

t_object	*init_objects(int obj_cnt)
{
	t_object	*objects;
	int			i;

	objects = malloc(sizeof(t_object) * obj_cnt);
	if (!objects)
		return (NULL);
	i = 0;
	while (i < obj_cnt)
	{
		objects[i] = object(i);
		i++;
	}
	return (objects);
}


void	set_as_sphere(t_object *object)
{
	object->intersect = intersect_sphere;
	object->normal_at = normal_at_sphere;
}

t_object	sphere(int id)
{
	t_object	new_sphere;

	new_sphere.transformation = init_id_matrix(4, 4);
	new_sphere.material = material();
	new_sphere.id = id;
	new_sphere.intersect = intersect_sphere;
	new_sphere.normal_at = normal_at_sphere;
	return (new_sphere);
}

t_object	plane(int id)
{
	t_object	new_plane;
	new_plane.transformation = init_id_matrix(4, 4);
	new_plane.material = material();
	new_plane.id = id;
	new_plane.intersect = intersect_plane;
	new_plane.normal_at = normal_at_plane;
}
