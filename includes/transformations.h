/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:18:03 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 22:18:05 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H
# include "matrices.h"

struct s_shear
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
};

t_matrix	init_id_matrix(int rows, int cols);
t_matrix	id_matrix(t_matrix matrix);
t_matrix	transpose(t_matrix matrix);
t_matrix	inversion(t_matrix matrix);
t_matrix	translation(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	rotation_x(double radiants);
t_matrix	rotation_y(double radiants);
t_matrix	rotation_z(double radiants);
t_matrix	shearing(struct s_shear params);


#endif