/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:32:43 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/23 14:33:54 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*gnl_append(char *line, char c, int *len)
{
	char	*tmp;
	int		i;

	tmp = malloc(*len + 2);
	if (!tmp)
		return (free(line), NULL);
	i = 0;
	while (i < *len)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[*len] = c;
	tmp[*len + 1] = '\0';
	free(line);
	(*len)++;
	return (tmp);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	char	c;
	ssize_t	n;
	int		len;

	if (fd < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	len = 0;
	n = 1;
	while (n > 0)
	{
		n = read(fd, &c, 1);
		if (n <= 0)
			break ;
		line = gnl_append(line, c, &len);
		if (!line || c == '\n')
			break ;
	}
	if (n <= 0 && len == 0)
		return (free(line), NULL);
	line[len] = '\0';
	return (line);
}
