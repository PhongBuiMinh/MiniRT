/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:09:17 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/05 19:14:02 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define EPSILON 0.0001
# define VECTOR 0
# define POINT 1

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_projectile
{
	t_tuple	*position;
	t_tuple	*velocity;
}	t_projectile;

typedef struct environment
{
	t_tuple	*gravity;
	t_tuple	*wind;
}	t_environment;

#endif