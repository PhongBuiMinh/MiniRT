/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:09:17 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/23 18:50:18 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define PI 3.14159265358979323846
# define EPSILON 0.0001
# define VECTOR 0
# define POINT 1
# define MULTITHREADING true

# define WIDTH 400
# define HEIGHT 400

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <float.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "tuple.h"
# include "canvas.h"
# include "matrices.h"
# include "rays.h"
# include "intersections.h"
# include "light.h"
# include "objects.h"
# include "world.h"
# include "helper_math.h"
# include "transformations.h"
# include "geometry.h"
# include "render.h"
# include "program.h"
# include "scene.h"
# include "parser.h"

# ifdef __linux__
#  define ESC 65307
# elif defined(__APPLE__)
#  define ESC 53
# endif

#endif