/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:30:56 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 19:57:43 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	recursive_itoa(char *string, int n, int *i)
{
	if (n / 10 != 0)
		recursive_itoa(string, n / 10, i);
	string[(*i)++] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(find_len(n) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
	}
	recursive_itoa(str, n, &i);
	str[i] = '\0';
	return (str);
}
