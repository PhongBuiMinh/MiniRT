/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:32 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:57:14 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	m_init(int rows, int cols)
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

void	m_print(t_matrix matrix)
{
	int	x;
	int	y;

	x = 0;
	if (matrix.rows <= 0 || matrix.cols <= 0)
	{
		printf("dont work");
		return ;
	}
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

t_matrix	m_multiply(t_matrix a, t_matrix b)
{
	t_matrix	product_matrix;
	int			x;
	int			y;
	int			k;
	double		value;

	product_matrix = m_init(a.rows, b.cols);
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

int	m_equal(t_matrix matrix_a, t_matrix matrix_b)
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

t_matrix	submatrix(t_matrix matrix, int row, int col)
{
	t_matrix	submatrix;
	int			i;
	int			j;
	int			x;
	int			y;

	submatrix = m_init(matrix.rows - 1, matrix.cols - 1);
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

t_tuple	m_apply(t_matrix matrix, t_tuple tuple)
{
	t_tuple	product_tuple;
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		product_tuple.data[x] = 0;
		while (y < 4)
		{
			product_tuple.data[x] += matrix.data[x][y] * tuple.data[y];
			y++;
		}
		x++;
	}
	return (product_tuple);
}


