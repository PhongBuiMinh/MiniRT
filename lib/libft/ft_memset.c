/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:40:49 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 22:56:18 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				a;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	a = 0;
	while (len > 0)
	{
		ptr[a] = c;
		a++;
		len--;
	}
	return (b);
}

// int main(void)
// {
// 	char str[] = "Hello World";
// 	printf("\n %s \n", ft_memset(str, '3', 5));
// }
