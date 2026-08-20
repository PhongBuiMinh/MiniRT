/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 00:00:00 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/20 18:23:19 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	token_count(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	is_normalized_range(t_tuple dir)
{
	if (dir.x < -1.0 || dir.x > 1.0)
		return (0);
	if (dir.y < -1.0 || dir.y > 1.0)
		return (0);
	if (dir.z < -1.0 || dir.z > 1.0)
		return (0);
	return (1);
}

t_matrix	build_rotation_from_y(const t_tuple *new_y)
{
	t_matrix	rot;
	t_tuple		new_z;
	t_tuple		new_x;

	if (fabs(new_y->x) < 0.99)
		new_z = normalize(cross(*new_y, vector(1, 0, 0)));
	else
		new_z = normalize(cross(*new_y, vector(0, 0, 1)));
	new_x = cross(*new_y, new_z);
	rot = init_id_matrix(4, 4);
	rot.data[0][0] = new_x.x;
	rot.data[0][1] = new_x.y;
	rot.data[0][2] = new_x.z;
	rot.data[1][0] = new_y->x;
	rot.data[1][1] = new_y->y;
	rot.data[1][2] = new_y->z;
	rot.data[2][0] = new_z.x;
	rot.data[2][1] = new_z.y;
	rot.data[2][2] = new_z.z;
	return (rot);
}
