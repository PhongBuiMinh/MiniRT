/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:04:12 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:54:32 by bpetrovi         ###   ########.fr       */
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

void	set_transformation(t_sphere *sphere, t_matrix transformation)
{
	sphere->transformation = transformation;
}

t_sphere	sphere(int id)
{
	t_sphere	new_sphere;

	new_sphere.id = id;
	new_sphere.transformation = init_id_matrix(4, 4);
	new_sphere.material = material();
	return (new_sphere);
}