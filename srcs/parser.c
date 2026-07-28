/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/28 21:40:16 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	dispatch_line(char **tokens, t_scene *scene)
{
	if (!tokens || !tokens[0])
		return (1);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (parse_ambient(tokens, scene));
	if (ft_strcmp(tokens[0], "C") == 0)
		return (parse_camera(tokens, scene));
	if (ft_strcmp(tokens[0], "L") == 0)
		return (parse_light(tokens, scene));
	if (ft_strcmp(tokens[0], "sp") == 0)
		return (parse_sphere(tokens, scene));
	if (ft_strcmp(tokens[0], "pl") == 0)
		return (parse_plane(tokens, scene));
	if (ft_strcmp(tokens[0], "cy") == 0)
		return (parse_cylinder(tokens, scene));
	return (0);
}

// function for test
int	process_line(char *line, t_scene *scene)
{
	char	*trimmed;
	char	**tokens;
	int		result;

	dprintf(2, "RAW: [%s]\n", line);
	trimmed = ft_strtrim(line, " \t\r\n");
	if (!trimmed)
		return (0);
	dprintf(2, "TRIMMED: [%s]\n", trimmed);
	if (trimmed[0] == '\0')
		return (free(trimmed), 1);
	tokens = ft_split(trimmed, ' ');
	free(trimmed);
	if (!tokens)
		return (0);
	if (tokens[0])
		dprintf(2, "TOKEN0: [%s]\n", tokens[0]);
	if (tokens[1])
		dprintf(2, "TOKEN1: [%s]\n", tokens[1]);
	if (tokens[2])
		dprintf(2, "TOKEN2: [%s]\n", tokens[2]);
	if (tokens[3])
		dprintf(2, "TOKEN3: [%s]\n", tokens[3]);
	result = dispatch_line(tokens, scene);
	dprintf(2, "DISPATCH RESULT: %d\n", result);
	free_tokens(tokens);
	return (result);
}

// static int	process_line(char *line, t_scene *scene)
// {
// 	char	*trimmed;
// 	char	**tokens;
// 	int		result;

// 	trimmed = ft_strtrim(line, " \t\r\n");
// 	if (!trimmed)
// 		return (0);
// 	if (trimmed[0] == '\0')
// 		return (free(trimmed), 1);
// 	tokens = ft_split(trimmed, ' ');
// 	free(trimmed);
// 	if (!tokens)
// 		return (0);
// 	result = dispatch_line(tokens, scene);
// 	free_tokens(tokens);
// 	return (result);
// }

int	validate_scene(t_scene *scene)
{
	if (!scene->has_ambient)
		return (0);
	if (!scene->has_camera)
		return (0);
	if (!scene->has_light)
		return (0);
	if (scene->obj_count <= 0)
		return (0);
	return (1);
}

// Temporary gnl
char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	ssize_t	n;
	int		len;

	line = malloc(1);
	if (!line)
		return (NULL);
	len = 0;
	while ((n = read(fd, &c, 1)) > 0)
	{
		char	*tmp = realloc(line, len + 2);
		if (!tmp)
		{
			free(line);
			return (NULL);
		}
		line = tmp;
		line[len++] = c;
		if (c == '\n')
			break ;
	}
	if (n <= 0 && len == 0)
	{
		free(line);
		return (NULL);
	}
	line[len] = '\0';
	return (line);
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
