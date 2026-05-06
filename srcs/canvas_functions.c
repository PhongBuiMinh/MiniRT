/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:35:42 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/06 10:44:22 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_tuple	color(float r, float g, float b)
{
	return (vector(r, g, b));
}

t_tuple	**init_canvas(int x, int y)
{
	t_tuple	**canvas;
	int		i;
	int		d;

	canvas = malloc((y + 1) * sizeof(t_tuple *));
	if (!canvas)
		return (NULL);
	canvas[y] = NULL;
	i = 0;
	while (i < y)
	{
		d = 0;
		canvas[i] = malloc(x * sizeof(t_tuple));
		if (!canvas[i])
			return (free_canvas(canvas), NULL);
		while (d < x)
		{
			canvas[i][d] = color(0, 0, 0);
			d++;
		}
		i++;
	}
	return (canvas);
}

void	free_canvas(t_tuple **canvas)
{
	int	i;

	i = 0;
	if (!canvas)
		return ;
	while (canvas[i])
	{
		free(canvas[i]);
		i++;
	}
	free(canvas);
}
