/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:46:43 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:57:02 by bpetrovi         ###   ########.fr       */
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
t_matrix	m_init(int rows, int cols);
t_matrix	m_multiply(t_matrix a, t_matrix b);
t_tuple		m_apply(t_matrix matrix, t_tuple tuple);
int			m_equal(t_matrix matrix_a, t_matrix matrix_b);
void		m_print(t_matrix matrix);


#endif