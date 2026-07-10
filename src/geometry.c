/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:40:19 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:03:52 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	magnitude(t_tuple	tuple)
{
	double	magnitude;

	magnitude = 0;
	magnitude += tuple.x * tuple.x;
	magnitude += tuple.y * tuple.y;
	magnitude += tuple.z * tuple.z;
	magnitude += tuple.w * tuple.w;
	return (sqrtf(magnitude));
}

double	dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	return (vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}

t_tuple	normalize(t_tuple tuple)
{
	return (t_divide(tuple, magnitude(tuple)));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (t_substract(in,
			t_scale
			(t_scale(normal, 2), dot(in, normal))));
}
