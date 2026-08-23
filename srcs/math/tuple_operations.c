/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 03:32:06 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/23 19:27:39 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
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
	if (divider == 0)
		return (tuple);
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
