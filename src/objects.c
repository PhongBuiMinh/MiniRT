/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:04:12 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 19:09:59 by bpetrovi         ###   ########.fr       */
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

void	object_init(t_object *object)
{
	object->material = material();
	object->transformation = init_id_matrix(4, 4);
}

t_object	*sphere_create(int id)
{
	t_sphere	*new_sphere;

	new_sphere = malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (NULL);
	object_init(&new_sphere->base_obj);
	new_sphere->base_obj.intersect = intersect_sphere;
	new_sphere->base_obj.normal_at = normal_at_sphere;
	new_sphere->base_obj.id = id;
	return ((t_object *)new_sphere);
}

t_object	*plane_create(int id)
{
	t_plane	*new_plane;

	new_plane = malloc(sizeof(t_plane));
	if (!new_plane)
		return (NULL);
	object_init(&new_plane->base_obj);
	new_plane->base_obj.intersect = intersect_plane;
	new_plane->base_obj.normal_at = normal_at_plane;
	new_plane->base_obj.id = id;
	return ((t_object *)new_plane);
}

t_object	*cylinder_create(int id)
{
	t_cylinder	*new_cylinder;

	new_cylinder = malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		return (NULL);
	object_init(&new_cylinder->base_obj);
	new_cylinder->base_obj.intersect = intersect_cylinder;
	new_cylinder->base_obj.normal_at = normal_at_cylinder;
	new_cylinder->max = INFINITY;
	new_cylinder->min = -INFINITY;
	new_cylinder->closed = false;
	new_cylinder->base_obj.id = id;
	return ((t_object *)new_cylinder);
}

void	free_objects(t_object **ptr, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		free(ptr[i]);
		i++;
	}
}