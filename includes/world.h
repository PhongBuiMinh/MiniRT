/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:45:00 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/12 16:45:52 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "light.h"
# include "objects.h"
# include "rays.h"
# include "intersections.h"
# include "scene.h"

typedef struct s_camera	t_camera;

typedef struct s_world
{
	t_light		light;
	t_object	**objects;
	int			object_cnt;
	t_tuple		ambient;
}	t_world;

int				build_world_from_scene(const t_scene *scene, t_world *world,
					t_camera *camera);
t_world			world_default(void);
t_intersections	world_intersect(t_world world, t_ray ray);
bool			is_shadowed(t_world world, t_tuple point);

#endif
