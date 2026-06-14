/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:45:12 by fbui-min          #+#    #+#             */
/*   Updated: 2026/06/14 17:45:17 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "tuple.h"

typedef struct s_matrix2
{
	double	m[2][2];
}	t_matrix2;

typedef struct s_matrix3
{
	double	m[3][3];
}	t_matrix3;

typedef struct s_matrix4
{
	double	m[4][4];
}	t_matrix4;

t_matrix4	matrix4_rows(t_tuple r0, t_tuple r1, t_tuple r2, t_tuple r3);
t_matrix3	matrix3_rows(t_tuple r0, t_tuple r1, t_tuple r2);
t_matrix2	matrix2_rows(t_tuple r0, t_tuple r1);

t_matrix4	matrix4_identity(void);

/* equality */

int			matrix4_equal(t_matrix4 a, t_matrix4 b);

/* multiplication */

t_matrix4	matrix4_mul(t_matrix4 a, t_matrix4 b);
t_tuple		matrix4_mul_tuple(t_matrix4 a, t_tuple t);

/* transpose */

t_matrix4	matrix4_transpose(t_matrix4 m);

/* submatrices */

t_matrix3	matrix4_submatrix(t_matrix4 m, int row, int col);
t_matrix2	matrix3_submatrix(t_matrix3 m, int row, int col);

/* determinants */

double		matrix2_det(t_matrix2 m);
double		matrix3_det(t_matrix3 m);
double		matrix4_det(t_matrix4 m);

/* minors & cofactors */

double		matrix3_minor(t_matrix3 m, int row, int col);
double		matrix3_cofactor(t_matrix3 m, int row, int col);
double		matrix4_minor(t_matrix4 m, int row, int col);
double		matrix4_cofactor(t_matrix4 m, int row, int col);

/* inversion */

int			matrix4_is_invertible(t_matrix4 m);
t_matrix4	matrix4_inverse(t_matrix4 m);

#endif
