/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:32:43 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/10 21:33:21 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*gnl_append(char *line, char c, int *len)
{
	char	*tmp;

	tmp = realloc(line, *len + 2);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	line = tmp;
	line[(*len)++] = c;
	return (line);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	char	c;
	ssize_t	n;
	int		len;

	if (fd < 0)
		return (NULL);
	line = malloc(2);
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
