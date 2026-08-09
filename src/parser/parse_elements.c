/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/09 15:02:51 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (0);
	return (1);
}

// Format: A ratio R,G,B
int	parse_ambient(char **tokens, t_scene *scene)
{
	double	ratio;
	t_color	color;

	if (scene->has_ambient || token_count(tokens) != 3)
		return (0);
	if (!is_valid_number(tokens[1]))
		return (0);
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
		return (0);
	if (!parse_color(tokens[2], &color))
		return (0);
	scene->ambient_ratio = ratio;
	scene->ambient_color = color;
	scene->has_ambient = 1;
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

	if (scene->has_camera || token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!parse_tuple(tokens[2], &dir))
		return (0);
	if (!is_normalized_range(dir))
		return (0);
	normalize_tuple(&dir);
	if (!is_valid_number(tokens[3]))
		return (0);
	fov = ft_atof(tokens[3]);
	if (fov <= 0.0 || fov >= 180.0)
		return (0);
	scene->cam_pos = pos;
	scene->cam_dir = dir;
	scene->cam_fov = fov;
	scene->has_camera = 1;
	return (1);
}

// Format: L x,y,z brightness [R,G,B]
int	parse_light(char **tokens, t_scene *scene)
{
	t_tuple	pos;
	double	brightness;
	t_color	color;

	if (scene->has_light || token_count(tokens) != 4)
		return (0);
	if (!parse_tuple(tokens[1], &pos))
		return (0);
	if (!is_valid_number(tokens[2]))
		return (0);
	brightness = ft_atof(tokens[2]);
	if (brightness < 0.0 || brightness > 1.0)
		return (0);
	if (!parse_color(tokens[3], &color))
		return (0);
	scene->pos = pos;
	scene->intensity = vector(
		color.r * brightness,
		color.g * brightness,
		color.b * brightness
	);
	scene->has_light = 1;
	return (1);
}
