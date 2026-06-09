/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:45:00 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/09 21:27:03 by bpetrovi         ###   ########.fr       */
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
	int			obj_c;
}	t_world;

typedef struct s_comps
{
	t_sphere	sphere;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
}	t_comps;

t_comps			prepare_computations(t_intersection is, t_ray r);
t_world			world_default(void);
t_intersections	world_intersect(t_ray ray, t_world world);

#endif