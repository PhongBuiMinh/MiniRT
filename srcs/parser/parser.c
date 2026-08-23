/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/23 05:57:19 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_scene(t_scene *scene)
{
	if (!scene->has_ambient)
		return (0);
	if (!scene->has_camera)
		return (0);
	if (!scene->has_light)
		return (0);
	if (scene->object_cnt <= 0)
		return (0);
	return (1);
}

static int	dispatch_line(char **tokens, t_scene *scene)
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

static int	process_line(char *line, t_scene *scene)
{
	char	*trimmed;
	char	**tokens;
	int		result;

	remove_comment(line);
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

static int	parse_lines(int fd, t_program *prog)
{
	t_scene *scene;
	char	*line;
	int		line_no;
	int		success;

	scene = &prog->scene;
	success = 1;
	line_no = 0;
	line = ft_get_next_line(fd);
	while (success && line)
	{
		line_no++;
		success = process_line(line, scene);
		if (!success)
			fatal_line(line, line_no, prog);
		free(line);
		line = ft_get_next_line(fd);
	}
	return (success);
}

int	parse_scene_file(const char *path, t_program *prog)
{
	int		fd;
	t_scene	*scene;

	scene = &prog->scene;
	ft_bzero(scene, sizeof(t_scene));
	if (!has_rt_extension(path))
		fatal("Scene file must have a .rt extension", NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		fatal("Cannot open scene file", NULL);
	if (!setup_objects(path, scene))
		return (close(fd), 0);
	if (!parse_lines(fd, prog))
		return (close(fd), 0);
	close(fd);
	return (validate_scene(scene));
}

// function for test
// int	process_line(char *line, t_scene *scene)
// {
// 	char	*trimmed;
// 	char	**tokens;
// 	int		result;

// 	dprintf(2, "RAW: [%s]\n", line);
// 	trimmed = ft_strtrim(line, " \t\r\n");
// 	if (!trimmed)
// 		return (0);
// 	dprintf(2, "TRIMMED: [%s]\n", trimmed);
// 	if (trimmed[0] == '\0')
// 		return (free(trimmed), 1);
// 	tokens = ft_split(trimmed, ' ');
// 	free(trimmed);
// 	if (!tokens)
// 		return (0);
// 	if (tokens[0])
// 		dprintf(2, "TOKEN0: [%s]\n", tokens[0]);
// 	if (tokens[1])
// 		dprintf(2, "TOKEN1: [%s]\n", tokens[1]);
// 	if (tokens[2])
// 		dprintf(2, "TOKEN2: [%s]\n", tokens[2]);
// 	if (tokens[3])
// 		dprintf(2, "TOKEN3: [%s]\n", tokens[3]);
// 	result = dispatch_line(tokens, scene);
// 	dprintf(2, "DISPATCH RESULT: %d\n", result);
// 	free_tokens(tokens);
// 	return (result);
// }
