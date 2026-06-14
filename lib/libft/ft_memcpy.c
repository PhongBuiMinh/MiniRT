/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:38:24 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/18 18:07:11 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			a;

	a = 0;
	if (dst == src || n == 0)
		return (dst);
	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	while (a < n)
	{
		destination[a] = source[a];
		a++;
	}
	return (dst);
}

// #include <stdio.h>
// int main()
// {
// 	char string[] = "JoeyKilledFaker";
// 	char string2[] = "Yoje";
// 	printf("%s \n", ft_memcpy(string, string2, 4));

// }