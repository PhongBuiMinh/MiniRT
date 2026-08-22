/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:43:44 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/08/22 18:22:47 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	number;
	int			minus;

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
	number *= minus;
	if (number > 2147483647)
		return (2147483647);
	else if (number < -2147483648)
		return (-2147483648);
	return (number);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*number = "    -2147483648";
// 	printf("%d \n", ft_atoi(number));
// }
