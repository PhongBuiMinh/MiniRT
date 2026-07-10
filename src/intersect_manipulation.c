/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:11:41 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/10 20:17:58 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	xs_grow(t_intersections *xs)
{
	t_intersection	*new_array;
	int				i;

	i = 0;
	new_array = malloc(sizeof(t_intersection) * (xs->capacity * 2));
	if (!new_array)
		return (false);
	while (i < xs->count)
	{
		new_array[i] = xs->intersections[i];
		i++;
	}
	free(xs->intersections);
	xs->intersections = new_array;
	xs->capacity *= 2;
	return (true);
}

void	xs_swap(t_intersections *xs, int i, int j)
{
	t_intersection	temp;

	temp = xs->intersections[i];
	xs->intersections[i] = xs->intersections[j];
	xs->intersections[j] = temp;
}

void	quick_sort(t_intersections *xs, int left, int right)
{
	int				pivot;
	int				i;
	int				j;

	if (left >= right)
		return ;
	pivot = (left + right) / 2;
	xs_swap(xs, pivot, right);
	i = left;
	j = left;
	while (j < right)
	{
		if (xs->intersections[j].t < xs->intersections[right].t)
		{
			xs_swap(xs, j, i);
			i++;
		}
		j++;
	}
	xs_swap(xs, i, right);
	quick_sort(xs, left, i - 1);
	quick_sort(xs, i + 1, right);
}

void	xs_sort(t_intersections *xs)
{
	quick_sort(xs, 0, xs->count - 1);
}

bool	xs_push(t_intersections *xs, t_intersection i)
{
	if (xs->count == xs->capacity)
	{
		if (!xs_grow(xs))
			return (xs->err = true, false);
	}
	xs->intersections[xs->count] = i;
	xs->count++;
	return (true);
}

//bool	xs_append(t_intersections *dst, t_intersections src)
//{
//	int	i;

//	i = 0;
//	while (i < src.count)
//	{
//		if (!xs_push(dst, src.intersections[i]))
//			return (free(src.intersections), free(dst->intersections), false);
//		i++;
//	}
//	free(src.intersections);
//	return (true);
//}
