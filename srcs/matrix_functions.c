/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:32 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/13 19:11:37 by bpetrovi         ###   ########.fr       */
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

void	init_matrix(t_matrix *matrix, int rows, int cols)
{
	int	y;
	int	x;

	x = 0;
	matrix->rows = rows;
	matrix->cols = cols;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			matrix->data[x][y] = 0;
			y++;
		}
		x++;
	}
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

void	init_ind_matrix(t_matrix *indentitiy_matrix, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	indentitiy_matrix->rows = rows;
	indentitiy_matrix->cols = cols;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (y == x)
				indentitiy_matrix->data[x][y] = 1;
			else
				indentitiy_matrix->data[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	ind_matrix(t_matrix *new_matrix, t_matrix matrix)
{
	t_matrix	indentity_matrix;

	init_ind_matrix(&indentity_matrix, matrix.rows, matrix.cols);
	if (!multiply_matrices(new_matrix, matrix, indentity_matrix))
		return (0);
	return (1);
}

// Still to be worked on

int	multiply_matrices(t_matrix *new_matrix, t_matrix a, t_matrix b)
{
	int		x;
	int		y;
	int		k;
	double	value;

	if (a.cols != b.rows)
		return (0);
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
			new_matrix->data[x][y] = value;
			y++;
		}
		x++;
	}
	return (1);
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

void	transpose_matrix(t_matrix *matrix_a)
{
	t_matrix	copy;
	int			x;
	int			y;

	copy = *matrix_a;
	x = 0;
	while (x < matrix_a->rows)
	{
		y = 0;
		while (y < matrix_a->cols)
		{
			matrix_a->data[x][y] = copy.data[y][x];
			y++;
		}
		x++;
	}
}

int	determinant(t_matrix matrix)
{
	return (matrix.data[0][0] * matrix.data[1][1] - matrix.data[0][1] * matrix.data[1][0]);
}

void	submatrix(t_matrix *submatrix, t_matrix matrix, int row, int col)
{
	int			i;
	int			j;
	int			x;
	int			y;

	init_matrix(submatrix, matrix.rows - 1, matrix.cols - 1);
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
			submatrix->data[x][y] = matrix.data[i][j];
			j++;
			y++;
		}
		x++;
		i++;
	}
}
