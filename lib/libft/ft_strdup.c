/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:58:58 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 19:58:23 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		a;
	char		*ptr;

	i = 0;
	a = 0;
	while (s1[i])
		i++;
	ptr = malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (a < i)
	{
		ptr[a] = s1[a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
