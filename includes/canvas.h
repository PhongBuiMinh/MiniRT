/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:04:04 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/06 10:15:12 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# include "tuple.h"

typedef struct s_canvas
{

}	t_canvas;

t_tuple	**init_canvas(int x, int y);
t_tuple	color(float r, float g, float b);
void	free_canvas(t_tuple **canvas);

#endif