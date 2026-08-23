/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:34:00 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 16:01:59 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_MATH_H
# define HELPER_MATH_H
# include "matrices.h"
# include "rays.h"

double	cofactor(t_matrix matrix, int row, int col);
double	determinant(t_matrix matrix);
double	minor(t_matrix matrix, int row, int col);
double	radians(double degrees);
bool	equal(double a, double b);
int		min(int a, int b);

#endif