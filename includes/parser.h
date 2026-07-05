/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 13:43:13 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 14:05:00 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"
# include "libft.h"
# include "minirt.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		parse_scene_file(const char *path, t_scene *scene);

int		parse_ambient(char **tokens, t_scene *scene);
int		parse_camera(char **tokens, t_scene *scene);
int		parse_light(char **tokens, t_scene *scene);
int		parse_sphere(char **tokens, t_scene *scene);
int		parse_plane(char **tokens, t_scene *scene);
int		parse_cylinder(char **tokens, t_scene *scene);

void	free_tokens(char **tokens);
void	normalize_tuple(t_tuple *v);
double	ft_atof(const char *str);

int		token_count(char **tokens);
int		parse_tuple(char *str, t_tuple *tuple);
int		is_valid_number(char *str);
int		parse_color(char *str, t_color *color);
int		ft_strcmp(const char *s1, const char *s2);

#endif
