/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/11 21:41:22 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	*data;
}	t_matrix;

int		matrices_equal(t_matrix matrix_a, t_matrix matrix_b);
int		ind_matrix(t_matrix *new_matrix, t_matrix matrix);
int		multiply_matrices(t_matrix *new_matrix, t_matrix a,
			t_matrix b);
int		init_matrix(t_matrix *matrix, int rows, int cols);
void	print_matrix(t_matrix matrix);
void	free_matrix(t_matrix *matrix);

// GETTER AND SETTER
double	get_matrix(t_matrix matrix, int row, int col);
void	set_matrix(t_matrix *matrix, int row, int col, double value);


#endif