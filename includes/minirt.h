/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:19:38 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/28 21:56:46 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include "render.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "color.h"
# include "MLX42/MLX42.h"
# include "scene.h"
// #include "../lib/minilibx-linux/mlx.h"

// WINDOW
# define WIDTH 350
# define HEIGHT 250
# define WORLD_MAX_OBJECTS 64

# ifdef __linux__
#  define ESC 65307
# elif defined(__APPLE__)
#  define ESC 53
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

//
typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	data[4][4];
}	t_matrix;

typedef struct s_camera
{
	t_matrix	transform;
	int			h_size;
	int			v_size;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		fov;
}	t_camera;

//
typedef struct s_light
{
	t_tuple	intensity;
	t_tuple	pos;
}	t_light;

//
typedef struct s_object
{
	t_tuple			(*normal_at)(t_tuple, struct s_object * self);
	// void			(*intersect)(struct s_object *self, t_ray, t_intersections *xs);
	// t_matrix		transformation;
	// t_material		material;
	int				id;
}	t_object;

typedef struct s_world
{
	t_light		light;
	t_object	*objects[WORLD_MAX_OBJECTS];
	int			object_cnt;
}	t_world;

typedef struct s_canvas
{
	t_tuple	**pixels;
	int		width;
	int		height;
}	t_canvas;

typedef struct s_program
{
	t_scene		scene;
	t_world		world;
	t_camera	camera;
	t_canvas	canvas;
	t_mlx		mlx;
}	t_program;

void		init_img(t_program *prog);
void		init_render(t_program *prog);
void		exit_minirt(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);
void		fatal(char *msg, t_program *prog);
int			build_world_from_scene(t_scene *s, t_world *w, t_camera *cam);
void		cleanup_program(t_program *prog);
void		render_minirt(t_program *prog);
t_canvas	canvas_new(int width, int height);

#endif
