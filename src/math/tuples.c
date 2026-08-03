/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 19:14:34 by bpetrovi         ###   ########.fr       */
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

t_tuple	t_negate(t_tuple tuple)
{
	tuple.x = -tuple.x;
	tuple.y = -tuple.y;
	tuple.z = -tuple.z;
	tuple.w = -tuple.w;
	return (tuple);
}

t_tuple	t_scale(t_tuple tuple, double t_scale)
{
	tuple.x = tuple.x * t_scale;
	tuple.y = tuple.y * t_scale;
	tuple.z = tuple.z * t_scale;
	tuple.w = tuple.w * t_scale;
	return (tuple);
}

t_tuple	t_divide(t_tuple tuple, double divider)
{
	tuple.x = tuple.x / divider;
	tuple.y = tuple.y / divider;
	tuple.z = tuple.z / divider;
	tuple.w = tuple.w / divider;
	return (tuple);
}

void	t_print(t_tuple tuple)
{
	printf("x: %f, ", tuple.x);
	printf("y: %f, ", tuple.y);
	printf("z: %f, ", tuple.z);
	printf("w: %f\n", tuple.w);
}