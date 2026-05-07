/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:04:04 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/07 23:26:18 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# include "tuple.h"

typedef struct s_canvas
{
	t_tuple	**pixels;
	int		width;
	int		height;
}	t_canvas;

t_tuple	color(float r, float g, float b);
int		init_canvas(t_canvas *canvas, int x, int y);
void	free_pixels(t_tuple **pixels);

#endif