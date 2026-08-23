/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:27:18 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 17:33:14 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
