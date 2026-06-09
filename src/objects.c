/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:04:12 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:06:42 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transformation(t_sphere *sphere, t_matrix transformation)
{
	sphere->transformation = transformation;
}

t_sphere	sphere(int id)
{
	t_sphere	new_sphere;

	new_sphere.id = id;
	new_sphere.transformation = init_ind_matrix(4, 4);
	new_sphere.material = material();
	return (new_sphere);
}