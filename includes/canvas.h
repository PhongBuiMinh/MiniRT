/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:04:04 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 20:10:50 by bpetrovi         ###   ########.fr       */
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

t_tuple		color(double r, double g, double b);
t_canvas	*init_canvas(int x, int y);
void		canvas_to_ppm(t_canvas *canvas);
void		write_pixel(t_canvas *canvas, int x, int y, t_tuple color);
void		write_star(t_canvas *canvas, int x, int y, t_tuple color);
void		free_pixels(t_tuple **pixels);

#endif