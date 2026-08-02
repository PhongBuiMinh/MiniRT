/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:09:17 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/02 19:43:53 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define PI 3.14159265358979323846
# define EPSILON 0.0001
# define VECTOR 0
# define POINT 1

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"
// # include "tuple.h"
// # include "canvas.h"
// # include "matrices.h"
// # include "rays.h"
// # include "intersections.h"
// # include "light.h"
// # include "objects.h"
// # include "world.h"
// # include "helper_math.h"
// # include "transformations.h"
// # include "geometry.h"
// # include "render.h"


// ADDITIONAL
# include <unistd.h>
# include "scene.h"
# include "MLX42/MLX42.h"
# include "minirt_parser.h"
# include "parser.h"

# define WIDTH 350
# define HEIGHT 250
# define WORLD_MAX_OBJECTS 64

# ifdef __linux__
#  define ESC 65307
# elif defined(__APPLE__)
#  define ESC 53
# endif

#endif