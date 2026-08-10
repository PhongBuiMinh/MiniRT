/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:53:24 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/10 22:21:18 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scene_add_object(t_scene *scene, t_object *obj)
{
	if (!scene || !obj)
		return (0);
	if (scene->object_idx == scene->object_cnt)
		return (0);
	scene->objects[scene->object_idx++] = obj;
	return (1);
}

static int	is_object_token(const char *s)
{
	if (!s)
		return (0);
	if (s[0] == 's' && s[1] == 'p')
		return (1);
	if (s[0] == 'p' && s[1] == 'l')
		return (1);
	if (s[0] == 'c' && s[1] == 'y')
		return (1);
	return (0);
}

int	count_objects(const char *path, int *object_cnt)
{
	int		fd;
	char	*line;
	char	*tmp;

	*object_cnt = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = ft_get_next_line(fd);
	while (line)
	{
		tmp = line;
		while (*tmp == ' ' || *tmp == '\t')
			tmp++;
		if (*tmp != '\0' && *tmp != '\n' && is_object_token(tmp))
			(*object_cnt)++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	setup_objects(const char *path, t_scene *scene)
{
	scene->objects = NULL;
	scene->object_cnt = 0;
	scene->object_idx = 0;
	if (!count_objects(path, &scene->object_cnt) || scene->object_cnt <= 0)
		return (0);
	scene->objects = malloc(scene->object_cnt * sizeof(*scene->objects));
	if (!scene->objects)
		return (0);
	return (1);
}
