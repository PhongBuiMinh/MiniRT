/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:34:00 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 11:45:49 by bpetrovi         ###   ########.fr       */
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

#endif