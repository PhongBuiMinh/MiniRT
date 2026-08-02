/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:23:04 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 22:58:29 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				a;
	unsigned char	*str;

	str = (unsigned char *)s;
	a = 0;
	while (n > 0)
	{
		str[a++] = '\0';
		n--;
	}
}
