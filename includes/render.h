/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:47:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:29:54 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:40:19 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:47:31 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:56:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 20:10:30 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "canvas.h"
# include "objects.h"
# include "light.h"

typedef struct s_scene
{
	t_canvas	canvas;
	t_tuple		origin;
	t_sphere	sphere;
	t_light		light;
	double		half;
	double		pixel_size;
	double		wall_z;
}	t_scene;

int		render_scene(t_scene *scene);
void	render_pixel(t_scene *scene, int x, int y);
void	render_row(t_scene *scene, int y);

#endif