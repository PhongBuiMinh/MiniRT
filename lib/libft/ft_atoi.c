/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:43:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/04 23:28:06 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	minus;

	minus = 1;
	number = 0;
	while (*str == 9 || *str == 10
		|| *str == 11 || *str == 12 || *str == 13 || *str == 12 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * minus);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*number = "    -2147483648";
// 	printf("%d \n", ft_atoi(number));
// }
