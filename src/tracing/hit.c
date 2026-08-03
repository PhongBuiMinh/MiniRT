/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:08:58 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:09:14 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_exists(t_intersection hit)
{
	return (hit.t >= 0);
}

t_intersection	hit(t_intersections xs)
{
	t_intersection	closest;
	int				i;
	int				found;

	i = 0;
	found = 0;
	while (i < xs.count)
	{
		if (xs.intersections[i].t >= 0)
		{
			if (!found || xs.intersections[i].t < closest.t)
			{
				closest = xs.intersections[i];
				found = 1;
			}
		}
		i++;
	}
	if (!found)
		closest.t = -1;
	return (closest);
}
