/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 05:42:40 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/10 14:22:44 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "tuple.h"

# define MAX_OBJECTS 64

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_obj_type;

// typedef struct s_scene_obj
// {
// 	t_obj_type	type;
// 	t_tuple		pos;
// 	t_tuple		orientation;
// 	double		diameter;
// 	double		height;
// 	t_color		color;
// }	t_scene_obj;

typedef struct s_scene
{
	int			has_ambient;
	double		ambient_ratio;
	t_color		ambient_color;

	int			has_camera;
	t_tuple		cam_pos;
	t_tuple		cam_dir;
	double		cam_fov;

	int			has_light;
	t_tuple		intensity;
	t_tuple		pos;

	t_object	**objects;
	int			object_cnt;
	int			object_idx;
}	t_scene;

#endif
