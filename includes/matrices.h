/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:39:32 by bpetrovi         ###   ########.fr       */
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


t_matrix	submatrix(t_matrix matrix, int row, int col);
t_matrix	init_matrix(int rows, int cols);
t_matrix	multiply_matrices(t_matrix a, t_matrix b);
t_tuple		mat_apply(t_matrix matrix, t_tuple tuple);
int			matrices_equal(t_matrix matrix_a, t_matrix matrix_b);
void		print_matrix(t_matrix matrix);


#endif