/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:21:14 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/04 15:56:20 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	i = 0;
	if (source < destination)
	{
		while (len-- > 0)
			destination[len] = source[len];
	}
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}

// int main()
// {
// 	char str[] = "HelloWorld";
// 	ft_memmove(str + 3, str, 5);
// 	printf("%s \n", str + 3);
// }