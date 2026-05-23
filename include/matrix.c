/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:50:04 by fbui-min          #+#    #+#             */
/*   Updated: 2026/05/23 19:11:13 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"

t_matrix4	matrix4_rows(t_tuple r0, t_tuple r1, t_tuple r2, t_tuple r3)
{
	t_matrix4	m;

	m.m[0][0] = r0.x; m.m[0][1] = r0.y; m.m[0][2] = r0.z; m.m[0][3] = r0.w;
	m.m[1][0] = r1.x; m.m[1][1] = r1.y; m.m[1][2] = r1.z; m.m[1][3] = r1.w;
	m.m[2][0] = r2.x; m.m[2][1] = r2.y; m.m[2][2] = r2.z; m.m[2][3] = r2.w;
	m.m[3][0] = r3.x; m.m[3][1] = r3.y; m.m[3][2] = r3.z; m.m[3][3] = r3.w;
	return (m);
}

t_matrix3	matrix3_rows(t_tuple r0, t_tuple r1, t_tuple r2)
{
	t_matrix3	m;

	m.m[0][0] = r0.x; m.m[0][1] = r0.y; m.m[0][2] = r0.z;
	m.m[1][0] = r1.x; m.m[1][1] = r1.y; m.m[1][2] = r1.z;
	m.m[2][0] = r2.x; m.m[2][1] = r2.y; m.m[2][2] = r2.z;
	return (m);
}

t_matrix2	matrix2_rows(t_tuple r0, t_tuple r1)
{
	t_matrix2	m;

	m.m[0][0] = r0.x; m.m[0][1] = r0.y;
	m.m[1][0] = r1.x; m.m[1][1] = r1.y;
	return (m);
}

t_matrix4	matrix4_identity(void)
{
	t_matrix4	m;
	int			r;
	int			c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (r == c)
				m.m[r][c] = 1.0;
			else
				m.m[r][c] = 0.0;
			c++;
		}
		r++;
	}
	return (m);
}

// Equality
int	matrix4_equal(t_matrix4 a, t_matrix4 b)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (!double_equal(a.m[r][c], b.m[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

// Multiplication
t_matrix4	matrix4_mul(t_matrix4 a, t_matrix4 b)
{
	t_matrix4	result;
	int			r;
	int			c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			result.m[r][c] =
				a.m[r][0] * b.m[0][c] +
				a.m[r][1] * b.m[1][c] +
				a.m[r][2] * b.m[2][c] +
				a.m[r][3] * b.m[3][c];
			c++;
		}
		r++;
	}
	return (result);
}

t_tuple	matrix4_mul_tuple(t_matrix4 a, t_tuple t)
{
	t_tuple	r;

	r.x = a.m[0][0] * t.x + a.m[0][1] * t.y + a.m[0][2] * t.z + a.m[0][3] * t.w;
	r.y = a.m[1][0] * t.x + a.m[1][1] * t.y + a.m[1][2] * t.z + a.m[1][3] * t.w;
	r.z = a.m[2][0] * t.x + a.m[2][1] * t.y + a.m[2][2] * t.z + a.m[2][3] * t.w;
	r.w = a.m[3][0] * t.x + a.m[3][1] * t.y + a.m[3][2] * t.z + a.m[3][3] * t.w;
	return (r);
}

// Transpose
t_matrix4	matrix4_transpose(t_matrix4 m)
{
	t_matrix4	t;
	int			r;
	int			c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			t.m[r][c] = m.m[c][r];
			c++;
		}
		r++;
	}
	return (t);
}

/* submatrices */

t_matrix2	matrix3_submatrix(t_matrix3 m, int row, int col)
{
	t_matrix2	result;
	int			r_src;
	int			c_src;
	int			r_dst;
	int			c_dst;

	r_dst = 0;
	r_src = 0;
	while (r_src < 3)
	{
		if (r_src == row)
		{
			r_src++;
			continue ;
		}
		c_dst = 0;
		c_src = 0;
		while (c_src < 3)
		{
			if (c_src == col)
			{
				c_src++;
				continue ;
			}
			result.m[r_dst][c_dst] = m.m[r_src][c_src];
			c_dst++;
			c_src++;
		}
		r_dst++;
		r_src++;
	}
	return (result);
}

t_matrix3	matrix4_submatrix(t_matrix4 m, int row, int col)
{
	t_matrix3	result;
	int			r_src;
	int			c_src;
	int			r_dst;
	int			c_dst;

	r_dst = 0;
	r_src = 0;
	while (r_src < 4)
	{
		if (r_src == row)
		{
			r_src++;
			continue ;
		}
		c_dst = 0;
		c_src = 0;
		while (c_src < 4)
		{
			if (c_src == col)
			{
				c_src++;
				continue ;
			}
			result.m[r_dst][c_dst] = m.m[r_src][c_src];
			c_dst++;
			c_src++;
		}
		r_dst++;
		r_src++;
	}
	return (result);
}

// Determinants
double	matrix2_det(t_matrix2 m)
{
	return (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]);
}

double	matrix3_det(t_matrix3 m)
{
	double	det;

	det = m.m[0][0] * matrix3_cofactor(m, 0, 0)
		+ m.m[0][1] * matrix3_cofactor(m, 0, 1)
		+ m.m[0][2] * matrix3_cofactor(m, 0, 2);
	return (det);
}

double	matrix4_det(t_matrix4 m)
{
	double det;

	det = m.m[0][0] * matrix4_cofactor(m, 0, 0)
		+ m.m[0][1] * matrix4_cofactor(m, 0, 1)
		+ m.m[0][2] * matrix4_cofactor(m, 0, 2)
		+ m.m[0][3] * matrix4_cofactor(m, 0, 3);
	return (det);
}

// Minors & cofactors
double	matrix3_minor(t_matrix3 m, int row, int col)
{
	t_matrix2	sub;

	sub = matrix3_submatrix(m, row, col);
	return (matrix2_det(sub));
}

double	matrix3_cofactor(t_matrix3 m, int row, int col)
{
	double	minor;

	minor = matrix3_minor(m, row, col);
	if ((row + col) % 2 != 0)
		minor = -minor;
	return (minor);
}

double	matrix4_minor(t_matrix4 m, int row, int col)
{
	t_matrix3	sub;

	sub = matrix4_submatrix(m, row, col);
	return (matrix3_det(sub));
}

double	matrix4_cofactor(t_matrix4 m, int row, int col)
{
	double	minor;

	minor = matrix4_minor(m, row, col);
	if ((row + col) % 2 != 0)
		minor = -minor;
	return (minor);
}

// Inversion
int	matrix4_is_invertible(t_matrix4 m)
{
	double	det;

	det = matrix4_det(m);
	return (!double_equal(det, 0.0));
}

t_matrix4	matrix4_inverse(t_matrix4 m)
{
	t_matrix4	inv;
	double		det;
	int			row;
	int			col;
	double		c;

	det = matrix4_det(m);
	if (double_equal(det, 0.0))
		return (matrix4_identity());
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = matrix4_cofactor(m, row, col);
			inv.m[col][row] = c / det;
			col++;
		}
		row++;
	}
	return (inv);
}
