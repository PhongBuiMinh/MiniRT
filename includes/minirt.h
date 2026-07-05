/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:19:38 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 13:39:34 by fbui-min         ###   ########.fr       */
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
# include "mlx.h"
# include "scene.h"
// #include "../lib/minilibx-linux/mlx.h"

// WINDOW
# define WIDTH 350
# define HEIGHT 250

# ifdef __linux__
#  define ESC 65307
# elif defined(__APPLE__)
#  define ESC 53
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	// int		width;
	// int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_world
{
}	t_world;

typedef struct s_camera
{
	// t_matrix	transform;
	int			h_size;
	int			v_size;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		fov;
}	t_camera;

typedef struct s_program
{
	t_scene		scene;
	t_world		world;
	t_camera	camera;
	t_canvas	canvas;
	t_mlx		mlx;
}	t_program;

void	init_img(t_program *prog);
void	init_render(t_program *prog);
int		exit_minirt(t_program *prog);
int		key_hook(int keycode, void *param);
void	fatal(char *msg, t_program *prog);

#endif
