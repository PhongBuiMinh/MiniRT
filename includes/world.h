/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:45:00 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 22:38:31 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "light.h"
# include "objects.h"
# include "rays.h"
# include "intersections.h"

typedef struct s_world
{
	t_light		light;
	t_sphere	*spheres;
	int			object_cnt;
}	t_world;

t_world			world_default(void);
t_intersections	world_intersect(t_world world, t_ray ray);
bool			is_shadowed(t_world world, t_tuple point);

#endif