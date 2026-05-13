/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/13 19:11:05 by bpetrovi         ###   ########.fr       */
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

int		matrices_equal(t_matrix matrix_a, t_matrix matrix_b);
int		ind_matrix(t_matrix *new_matrix, t_matrix matrix);
int		multiply_matrices(t_matrix *new_matrix, t_matrix a,
			t_matrix b);
int		determinant(t_matrix matrix);
void	init_matrix(t_matrix *matrix, int rows, int cols);
void	init_ind_matrix(t_matrix *indentitiy_matrix, int rows, int cols);
void	transpose_matrix(t_matrix *matrix_a);
void	print_matrix(t_matrix matrix);
void	submatrix(t_matrix *submatrix, t_matrix matrix, int row, int col);


#endif