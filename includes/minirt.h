/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:09:17 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/07 23:15:14 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define PI 3.14159265358979323846
# define MINIRT_H
# define EPSILON 0.0001
# define VECTOR 0
# define POINT 1

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "tuple.h"
# include "canvas.h"
# include "matrices.h"
# include "rays.h"
# include "intersections.h"
# include "light.h"

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct environment
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_environment;

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

#endif