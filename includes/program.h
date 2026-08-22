/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:19:38 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 15:38:40 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H
# define WORLD_MAX_OBJECTS 64

# include "tuple.h"
# include "scene.h"
# include "MLX42/MLX42.h"

typedef struct s_program
{
	t_scene		scene;
	t_world		world;
	t_camera	camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_program;

void		init_img(t_program *prog);
void		init_mlx(t_program *prog);
void		exit_minirt(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);
void		fatal(char *msg, t_program *prog);
void		fatal_line(char *line, int line_no, t_program *prog);
void		cleanup_program(t_program *prog);
void		render_minirt(t_program *prog);

#endif
