/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:53:24 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/23 05:25:10 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_object_color(t_object *obj, t_color color)
{
	obj->material.color = vector(color.r, color.g, color.b);
}

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
	if (s[2] != ' ' && s[2] != '\t'
		&& s[2] != '\n' && s[2] != '\0')
		return (0);
	if (ft_strncmp(s, "sp", 2) == 0)
		return (1);
	if (ft_strncmp(s, "pl", 2) == 0)
		return (1);
	if (ft_strncmp(s, "cy", 2) == 0)
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
		if (*tmp != '\0' && *tmp != '\n' && *tmp != '#'
			&& is_object_token(tmp))
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
	ft_bzero(scene->objects, scene->object_cnt * sizeof(*scene->objects));
	return (1);
}
