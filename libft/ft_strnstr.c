/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:21:11 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/03 22:00:15 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			a = 0;
			while (haystack[i + a] && needle[a]
				&& haystack[i + a] == needle[a] && i + a < len)
				a++;
			if (needle[a] == '\0')
				return (((char *)haystack + i));
		}
		i++;
	}
	return (NULL);
}
