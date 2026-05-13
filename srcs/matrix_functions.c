/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:32 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/13 19:44:48 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

t_matrix	init_matrix(int rows, int cols)
{
	t_matrix	new_matrix;
	int			y;
	int			x;

	x = 0;
	new_matrix.rows = rows;
	new_matrix.cols = cols;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			new_matrix.data[x][y] = 0;
			y++;
		}
		x++;
	}
	return (new_matrix);
}

void	print_matrix(t_matrix matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix.rows)
	{
		y = 0;
		printf("|");
		while (y < matrix.cols)
		{
			printf(" %f |", matrix.data[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

// Still to be worked on

t_matrix	init_ind_matrix(int rows, int cols)
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

t_matrix	ind_matrix(t_matrix matrix)
{
	t_matrix	indentity_matrix;

	indentity_matrix = init_ind_matrix(matrix.rows, matrix.cols);
	return (multiply_matrices(matrix, indentity_matrix));
}

// Still to be worked on

t_matrix	multiply_matrices(t_matrix a, t_matrix b)
{
	t_matrix	product_matrix;
	int			x;
	int			y;
	int			k;
	double		value;

	product_matrix = init_matrix(a.rows, b.cols);
	if (a.cols != b.rows)
		return (printf("these 2 matrices cannot be multiplied"),
			product_matrix);
	x = 0;
	while (x < a.rows)
	{
		y = 0;
		while (y < b.cols)
		{
			k = 0;
			value = 0;
			while (k < a.cols)
			{
				value += a.data[x][k] * b.data[k][y];
				k++;
			}
			product_matrix.data[x][y] = value;
			y++;
		}
		x++;
	}
	return (product_matrix);
}

int	matrices_equal(t_matrix matrix_a, t_matrix matrix_b)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix_a.rows)
	{
		y = 0;
		while (y < matrix_a.cols)
		{
			if (!equal(matrix_a.data[x][y], matrix_b.data[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

t_matrix	transpose_matrix(t_matrix matrix)
{
	t_matrix	transposed_matrix;
	int			x;
	int			y;

	x = 0;
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

int	determinant(t_matrix matrix)
{
	return (matrix.data[0][0] * matrix.data[1][1] - matrix.data[0][1] * matrix.data[1][0]);
}

t_matrix	submatrix(t_matrix matrix, int row, int col)
{
	t_matrix	submatrix;
	int			i;
	int			j;
	int			x;
	int			y;

	submatrix = init_matrix(matrix.rows - 1, matrix.cols - 1);
	x = 0;
	i = 0;
	while (i < matrix.rows)
	{
		if (i == row)
		{
			i++;
			continue ;
		}
		j = 0;
		y = 0;
		while (j < matrix.cols)
		{
			if (j == col)
			{
				j++;
				continue ;
			}
			submatrix.data[x][y] = matrix.data[i][j];
			j++;
			y++;
		}
		x++;
		i++;
	}
	return (submatrix);
}
