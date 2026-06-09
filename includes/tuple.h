/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:01:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:51:34 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

typedef union s_tuple
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	double	data[4];
}	t_tuple;

t_tuple	vector(double x, double y, double z);
t_tuple	point(double x, double y, double z);
t_tuple	t_add(t_tuple tuple_a, t_tuple tuple_b);
t_tuple	t_substract(t_tuple tuple_a, t_tuple tuple_b);
t_tuple	cross(t_tuple a, t_tuple b);
t_tuple	t_multiply(t_tuple a, t_tuple b);
t_tuple	t_negate(t_tuple tuple);
t_tuple	t_scale(t_tuple tuple, double t_scale);
t_tuple	t_divide(t_tuple tuple, double divider);
t_tuple	normalize(t_tuple tuple);
double	magnitude(t_tuple	tuple);
double	dot(t_tuple a, t_tuple b);
void	t_print(t_tuple tuple);

#endif
