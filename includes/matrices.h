/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/13 19:52:10 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	data[4][4];
}	t_matrix;


t_matrix	init_matrix(int rows, int cols);
t_matrix	ind_matrix(t_matrix matrix);
t_matrix	submatrix(t_matrix matrix, int row, int col);
t_matrix	multiply_matrices(t_matrix a, t_matrix b);
t_matrix	transpose_matrix(t_matrix matrix);
t_matrix	init_ind_matrix(int rows, int cols);
double		determinant(t_matrix matrix);
double		minor(t_matrix matrix, int row, int col);
int			matrices_equal(t_matrix matrix_a, t_matrix matrix_b);
void		print_matrix(t_matrix matrix);


#endif