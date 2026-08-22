/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 03:44:22 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 03:45:13 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
