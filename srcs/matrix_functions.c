/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:32 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/09 20:01:38 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	equal(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

float	get_matrix(t_matrix matrix, int row, int col)
{
	return (matrix.data[row * matrix.cols + col]);
}

void	set_matrix(t_matrix *matrix, int row, int col, float value)
{
	matrix->data[row * matrix->cols + col] = value;
}

int	init_matrix(t_matrix *matrix, int rows, int cols)
{
	int	y;
	int	x;

	x = 0;
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->data = malloc(rows * cols * sizeof(float));
	if (!matrix->data)
		return (-1);
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			set_matrix(matrix, x, y, 0);
			y++;
		}
		x++;
	}
	return (1);
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
			printf(" %f |", get_matrix(matrix, x, y));
			y++;
		}
		printf("\n");
		x++;
	}
}

int	multiply_matrices(t_matrix *new_matrix, t_matrix a,
		t_matrix b)
{
	int		x;
	int		y;
	int		k;
	float	value;

	if (a.cols != b.rows)
		return (-1);
	if (!init_matrix(new_matrix, a.rows, b.cols))
		return (-1);
	x = 0;
	while (x < new_matrix->rows)
	{
		y = 0;
		while (y < new_matrix->cols)
		{
			k = 0;
			value = 0;
			while (k < a.cols)
			{
				value += get_matrix(a, x, k) * get_matrix(b, k, y);
				k++;
			}
			set_matrix(new_matrix, x, y, value);
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
			if (!equal(get_matrix(matrix_a, x, y), get_matrix(matrix_b, x, y)))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	free_matrix(t_matrix *matrix)
{
	free(matrix->data);
}
