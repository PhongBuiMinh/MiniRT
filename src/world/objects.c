/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:04:12 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/22 03:45:09 by fbui-min         ###   ########.fr       */
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
