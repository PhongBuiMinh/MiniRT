/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/22 03:33:00 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	vector(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = VECTOR;
	return (tuple);
}

t_tuple	point(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = POINT;
	return (tuple);
}

t_tuple	t_add(t_tuple tuple_a, t_tuple tuple_b)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple_a.x + tuple_b.x;
	new_tuple.y = tuple_a.y + tuple_b.y;
	new_tuple.z = tuple_a.z + tuple_b.z;
	new_tuple.w = tuple_a.w + tuple_b.w;
	return (new_tuple);
}

t_tuple	t_substract(t_tuple tuple_a, t_tuple tuple_b)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple_a.x - tuple_b.x;
	new_tuple.y = tuple_a.y - tuple_b.y;
	new_tuple.z = tuple_a.z - tuple_b.z;
	new_tuple.w = tuple_a.w - tuple_b.w;
	return (new_tuple);
}

t_tuple	t_multiply(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x * b.x;
	new_tuple.y = a.y * b.y;
	new_tuple.z = a.z * b.z;
	new_tuple.w = a.w * b.w;
	return (new_tuple);
}
