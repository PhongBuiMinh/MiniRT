/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:27:18 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 19:02:00 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Still to be worked on

t_matrix	init_id_matrix(int rows, int cols)
{
	t_matrix	indentity_matrix;
	int			x;
	int			y;

	x = 0;
	indentity_matrix.rows = rows;
	indentity_matrix.cols = cols;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (y == x)
				indentity_matrix.data[x][y] = 1;
			else
				indentity_matrix.data[x][y] = 0;
			y++;
		}
		x++;
	}
	return (indentity_matrix);
}

t_matrix	id_matrix(t_matrix matrix)
{
	t_matrix	indentity_matrix;

	indentity_matrix = init_id_matrix(matrix.rows, matrix.cols);
	return (m_multiply(matrix, indentity_matrix));
}

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
	if (equal(det, 0))
		return (printf("cannot invert matrix: \n"), m_print(matrix), inverted_matrix.rows = -1, inverted_matrix);
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

t_matrix	translation(double x, double y, double z)
{
	t_matrix	translation_matrix;

	translation_matrix = init_id_matrix(4, 4);
	translation_matrix.data[0][3] = x;
	translation_matrix.data[1][3] = y;
	translation_matrix.data[2][3] = z;
	return (translation_matrix);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	scaling_matrix;

	scaling_matrix = init_id_matrix(4, 4);
	scaling_matrix.data[0][0] = x;
	scaling_matrix.data[1][1] = y;
	scaling_matrix.data[2][2] = z;
	return (scaling_matrix);
}

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

t_matrix	shearing(struct s_shear params)
{
	t_matrix	shear_matrix;

	shear_matrix = init_id_matrix(4, 4);
	shear_matrix.data[0][1] = params.xy;
	shear_matrix.data[0][2] = params.xz;
	shear_matrix.data[1][0] = params.yx;
	shear_matrix.data[1][2] = params.yz;
	shear_matrix.data[2][0] = params.zx;
	shear_matrix.data[2][1] = params.zy;
	return (shear_matrix);
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
