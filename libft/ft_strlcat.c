/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:09:45 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/03 18:21:41 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	c;
	size_t	i;
	size_t	a;

	a = 0;
	i = 0;
	c = 0;
	while (dst[c] && c < dstsize)
		c++;
	while (src[i])
		i++;
	if (c >= dstsize)
		return (dstsize + i);
	while (src[a] && c < dstsize - 1)
		dst[c++] = src[a++];
	dst[c] = '\0';
	return (c + i - a);
}
