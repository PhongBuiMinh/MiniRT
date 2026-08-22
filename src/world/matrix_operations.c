/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 03:52:39 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 03:53:41 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	transpose(t_matrix matrix)
{
	t_matrix	transposed_matrix;
	int			x;
	int			y;

	x = 0;
	transposed_matrix.rows = matrix.rows;
	transposed_matrix.cols = matrix.cols;
	while (x < matrix.rows)
	{
		y = 0;
		while (y < matrix.cols)
		{
			transposed_matrix.data[x][y] = matrix.data[y][x];
			y++;
		}
		x++;
	}
	return (transposed_matrix);
}

t_matrix	inversion(t_matrix matrix)
{
	t_matrix	inverted_matrix;
	double		det;
	int			x;
	int			y;

	x = 0;
	det = determinant(matrix);
	inverted_matrix.rows = matrix.rows;
	inverted_matrix.cols = matrix.cols;
	while (x < matrix.rows)
	{
		y = 0;
		while (y < matrix.cols)
		{
			inverted_matrix.data[y][x] = cofactor(matrix, x, y) / det;
			y++;
		}
		x++;
	}
	return (inverted_matrix);
}

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation;

	forward = normalize(t_substract(to, from));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	orientation = init_id_matrix(4, 4);
	orientation.data[0][0] = left.x;
	orientation.data[0][1] = left.y;
	orientation.data[0][2] = left.z;
	orientation.data[1][0] = true_up.x;
	orientation.data[1][1] = true_up.y;
	orientation.data[1][2] = true_up.z;
	orientation.data[2][0] = -forward.x;
	orientation.data[2][1] = -forward.y;
	orientation.data[2][2] = -forward.z;
	return (m_multiply(orientation,
			translation(-from.x, -from.y, -from.z)));
}
