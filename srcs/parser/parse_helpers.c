/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/23 18:46:10 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	has_rt_extension(const char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 3)
		return (0);
	return (ft_strcmp(path + len - 3, ".rt") == 0);
}

void	remove_comment(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	if (line[i] == '#')
		line[i] = '\0';
}

int	token_count(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

int	is_valid_direction(t_tuple *dir)
{
	dir->w = 0.0;
	if (dir->x < -1.0 || dir->x > 1.0
		|| dir->y < -1.0 || dir->y > 1.0
		|| dir->z < -1.0 || dir->z > 1.0)
		return (0);
	if (magnitude(*dir) == 0.0)
		return (0);
	*dir = normalize(*dir);
	return (1);
}

t_matrix	build_rotation_from_y(const t_tuple *new_y)
{
	t_matrix	rot;
	t_tuple		new_z;
	t_tuple		new_x;

	if (fabs(new_y->x) < 0.9)
		new_z = normalize(cross(*new_y, vector(1, 0, 0)));
	else
		new_z = normalize(cross(*new_y, vector(0, 0, 1)));
	new_x = cross(*new_y, new_z);
	rot = init_id_matrix(4, 4);
	rot.data[0][0] = new_x.x;
	rot.data[1][0] = new_x.y;
	rot.data[2][0] = new_x.z;
	rot.data[0][1] = new_y->x;
	rot.data[1][1] = new_y->y;
	rot.data[2][1] = new_y->z;
	rot.data[0][2] = new_z.x;
	rot.data[1][2] = new_z.y;
	rot.data[2][2] = new_z.z;
	return (rot);
}
