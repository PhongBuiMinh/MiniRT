/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:01:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/11 21:41:22 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

t_tuple	vector(double x, double y, double z);
t_tuple	point(double x, double y, double z);
t_tuple	add(t_tuple tuple_a, t_tuple tuple_b);
t_tuple	substract(t_tuple tuple_a, t_tuple tuple_b);
t_tuple	cross(t_tuple a, t_tuple b);
t_tuple	multiply_tuples(t_tuple a, t_tuple b);
t_tuple	negate(t_tuple tuple);
t_tuple	multiply(t_tuple tuple, double scalar);
t_tuple	divide(t_tuple tuple, double divider);
t_tuple	normalize(t_tuple tuple);
double	magnitude(t_tuple	tuple);
double	dot(t_tuple a, t_tuple b);
void	print_tuple(t_tuple tuple);
void	check_tuple(t_tuple tuple);

#endif
