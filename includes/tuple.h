/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:01:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/05 21:21:10 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	vector(float x, float y, float z);
t_tuple	point(float x, float y, float z);
t_tuple	add(t_tuple tuple_a, t_tuple tuple_b);
t_tuple	substract(t_tuple tuple_a, t_tuple tuple_b);
t_tuple	cross(t_tuple a, t_tuple b);
t_tuple	multiply_tuples(t_tuple a, t_tuple b);
float	magnitude(t_tuple	tuple);
float	dot(t_tuple a, t_tuple b);
void	negate(t_tuple *tuple);
void	multiply(t_tuple *tuple, float scalar);
void	divide(t_tuple *tuple, float divider);
void	normalize(t_tuple *tuple);
void	print_tuple(t_tuple tuple);
void	check_tuple(t_tuple tuple);

#endif
