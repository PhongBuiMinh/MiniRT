/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/07/05 07:29:03 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"
#include "minirt.h"

int	token_count(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	parse_color(char *str, t_color *color)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (!rgb)
		return (0);
	if (token_count(rgb) != 3)
		return (free_tokens(rgb), 0);
	i = 0;
	while (rgb[i])
	{
		if (!is_valid_number(rgb[i]))
			return (free_tokens(rgb), 0);
		i++;
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_tokens(rgb);
	if (color->r < 0 || color->r > 255 ||
		color->g < 0 || color->g > 255 ||
		color->b < 0 || color->b > 255)
		return (0);
	return (1);
}

// Format: A ratio R,G,B
int	parse_ambient(char **tokens, t_scene *scene)
{
	t_color	color;
	double	ratio;

	if (token_count(tokens) != 3)
		return (0);
	if (scene->has_ambient)
		return (0);
	if (!is_valid_number(tokens[1]))
		return (0);
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
		return (0);
	if (!parse_color(tokens[2], &color))
		return (0);
	scene->has_ambient = 1;
	scene->ambient_ratio = ratio;
	scene->ambient_color = color;
	return (1);
}

int	parse_tuple(char *str, t_tuple *tuple)
{
	char	**coords;
	int		i;

	coords = ft_split(str, ',');
	if (!coords)
		return (0);
	if (token_count(coords) != 3)
		return (free_tokens(coords), 0);
	i = 0;
	while (coords[i])
	{
		if (!is_valid_number(coords[i]))
			return (free_tokens(coords), 0);
		i++;
	}
	tuple->x = ft_atof(coords[0]);
	tuple->y = ft_atof(coords[1]);
	tuple->z = ft_atof(coords[2]);
	free_tokens(coords);
	return (1);
}

// Format: C x,y,z dx,dy,dz FOV
int	parse_camera(char **tokens, t_scene *scene)
{
	t_tuple	pos;
	t_tuple	dir;
	double	fov;

	if (token_count(tokens) != 4)
		return (0);
	if (scene->has_camera)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!parse_tuple(tokens[2], &dir))
		return (0);
	normalize_tuple(&dir);
	if (!is_valid_number(tokens[3]))
		return (0);
	fov = ft_atof(tokens[3]);
	if (fov < 0.0 || fov > 180.0)
		return (0);
	scene->has_camera = 1;
	scene->cam_pos = pos;
	scene->cam_dir = dir;
	scene->cam_fov = fov;
	return (1);
}

// Format: L x,y,z brightness [R,G,B]
int	parse_light(char **tokens, t_scene *scene)
{
	t_tuple	pos;
	double	brightness;
	t_color	color;

	if (token_count(tokens) != 3 && token_count(tokens) != 4)
		return (0);
	if (scene->has_light)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!is_valid_number(tokens[2]))
		return (0);
	brightness = ft_atof(tokens[2]);
	if (brightness < 0.0 || brightness > 1.0)
		return (0);
	if (tokens[3])
	{
		if (!parse_color(tokens[3], &color))
			return (0);
	}
	else
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
	}
	scene->has_light = 1;
	scene->light_pos = pos;
	scene->light_brightness = brightness;
	scene->light_color = color;
	return (1);
}
