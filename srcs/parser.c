/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 06:27:38 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "scene.h"
#include "libft.h"
#include "minirt.h"

int	parse_ambient(char **tokens, t_scene *scene);
int	parse_camera(char **tokens, t_scene *scene);
int	parse_light(char **tokens, t_scene *scene);
int	parse_sphere(char **tokens, t_scene *scene);
int	parse_plane(char **tokens, t_scene *scene);
int	parse_cylinder(char **tokens, t_scene *scene);

int	dispatch_line(char **tokens, t_scene *scene)
{
	if (!tokens || !tokens[0])
		return (1);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (parse_ambient(tokens, scene));
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (parse_camera(tokens, scene));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (parse_light(tokens, scene));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (parse_sphere(tokens, scene));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (parse_plane(tokens, scene));
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (parse_cylinder(tokens, scene));
	return (0);
}

static int	process_line(char *line, t_scene *scene)
{
	char	*trimmed;
	char	**tokens;
	int		result;

	trimmed = ft_strtrim(line, " \t\r\n");
	if (!trimmed)
		return (0);
	if (trimmed[0] == '\0')
		return (free(trimmed), 1);
	tokens = ft_split(trimmed, ' ');
	free(trimmed);
	if (!tokens)
		return (0);
	result = dispatch_line(tokens, scene);
	free_tokens(tokens);
	return (result);
}

int	validate_scene(t_scene *s)
{
	if (!s->has_ambient)
		return (0);
	if (!s->has_camera)
		return (0);
	if (!s->has_light)
		return (0);
	if (s->obj_count <= 0)
		return (0);
	return (1);
}

int	parse_scene_file(const char *path, t_scene *scene)
{
	int		fd;
	char	*line;
	int		success;

	ft_bzero(scene, sizeof(t_scene));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	success = 1;
	line = get_next_line(fd);
	while (success && line != NULL)
	{
		success = process_line(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!success)
		return (0);
	return (validate_scene(scene));
}
