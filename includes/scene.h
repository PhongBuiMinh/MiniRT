/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 05:42:40 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 06:18:04 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "tuple.h"
# include "color.h"

typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_obj_type;

typedef struct s_scene_obj
{
	t_obj_type	type;
	t_tuple		pos;
	t_tuple		orientation;
	double		diameter;
	double		height;
	t_color		color;
}	t_scene_obj;

// if (obj.type == OBJ_SPHERE)
//     pos, diameter, color
// else if (obj.type == OBJ_PLANE)
//     pos, orientation, color
// else if (obj.type == OBJ_CYLINDER)
//     pos, orientation, diameter, height, color

# define MAX_OBJECTS 64

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
	t_tuple		light_pos;
	double		light_brightness;
	t_color		light_color;

	t_scene_obj	objects[MAX_OBJECTS];
	int			obj_count;
}	t_scene;

int		parse_scene_file(const char *path, t_scene *scene);

#endif
