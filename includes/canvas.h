/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:04:04 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/12 15:01:08 by fbui-min         ###   ########.fr       */
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
int			scale_color(float c);
int			color_to_int(t_tuple color);
void		canvas_to_ppm(t_canvas *canvas);
void		write_pixel(t_canvas *canvas, int x, int y, t_tuple color);
void		free_pixels(t_tuple **pixels);
void		free_canvas(t_canvas *canvas);

#endif
