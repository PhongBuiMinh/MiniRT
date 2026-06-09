/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:29:53 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:42:57 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	discriminant(t_ray ray)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;

	sphere_to_ray = t_substract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	return (b * b - 4 * a * c);
}

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

double	cofactor(t_matrix matrix, int row, int col)
{
	double	minor_value;

	minor_value = minor(matrix, row, col);
	if ((row + col) % 2 == 1)
		return (-minor_value);
	return (minor_value);
}

double	determinant(t_matrix matrix)
{
	double	determinant;
	int		i;

	i = 0;
	determinant = 0;
	if (matrix.rows == 2 && matrix.cols == 2)
		return (matrix.data[0][0] * matrix.data[1][1]
			- matrix.data[0][1] * matrix.data[1][0]);
	while (i < matrix.rows)
	{
		determinant += cofactor(matrix, 0, i) * matrix.data[0][i];
		i++;
	}
	return (determinant);
}

double	minor(t_matrix matrix, int row, int col)
{
	return (determinant(submatrix(matrix, row, col)));
}

double	radians(double degrees)
{
	return (degrees / 180 * PI);
}