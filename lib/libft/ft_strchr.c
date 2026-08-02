/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:14:58 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 20:29:22 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	new_c;

	i = 0;
	new_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == (char)new_c)
			return ((char *)&s[i]);
		i++;
	}
	if (new_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
