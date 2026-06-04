/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:56:37 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/04 21:13:01 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H
# include "tuple.h"
# include "light.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_sphere
{
	t_matrix	transformation;
	t_tuple		origin;	
	t_material	material;
	int			id;
}	t_sphere;

t_ray		ray(t_tuple origin, t_tuple direction);
t_ray		ray_transform(t_ray ray, t_matrix transformation);
t_sphere	sphere(int id);
t_tuple		position(t_ray ray, int time);
void		set_transformation(t_sphere *sphere, t_matrix transformation);


#endif