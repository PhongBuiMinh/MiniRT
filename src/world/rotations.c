/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rortations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 03:39:17 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 03:40:01 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	rotation_x(double radiants)
{
	t_matrix	rotation_matrix;

	rotation_matrix = init_id_matrix(4, 4);
	rotation_matrix.data[1][1] = cos(radiants);
	rotation_matrix.data[1][2] = -sin(radiants);
	rotation_matrix.data[2][1] = sin(radiants);
	rotation_matrix.data[2][2] = cos(radiants);
	return (rotation_matrix);
}

t_matrix	rotation_y(double radiants)
{
	t_matrix	rotation_matrix;

	rotation_matrix = init_id_matrix(4, 4);
	rotation_matrix.data[0][0] = cos(radiants);
	rotation_matrix.data[0][2] = sin(radiants);
	rotation_matrix.data[2][0] = -sin(radiants);
	rotation_matrix.data[2][2] = cos(radiants);
	return (rotation_matrix);
}

t_matrix	rotation_z(double radiants)
{
	t_matrix	rotation_matrix;

	rotation_matrix = init_id_matrix(4, 4);
	rotation_matrix.data[0][0] = cos(radiants);
	rotation_matrix.data[0][1] = -sin(radiants);
	rotation_matrix.data[1][0] = sin(radiants);
	rotation_matrix.data[1][1] = cos(radiants);
	return (rotation_matrix);
}
