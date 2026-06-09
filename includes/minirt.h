/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:09:17 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:29:17 by bpetrovi         ###   ########.fr       */
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

//typedef struct s_projectile
//{
//	t_tuple	position;
//	t_tuple	velocity;
//}	t_projectile;

//typedef struct environment
//{
//	t_tuple	gravity;
//	t_tuple	wind;
//}	t_environment;


#endif