/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:45:03 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/06 19:58:47 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_start(char const *string, char const *charset)
{
	int	start;
	int	i;

	start = 0;
	while (string[start])
	{
		i = 0;
		while (charset[i])
		{
			if (charset[i] == string[start])
				break ;
			i++;
		}
		if (!charset[i])
			break ;
		start++;
	}
	return (start);
}

static int	check_end(char const *string, char const *charset)
{
	int	end;
	int	i;

	end = ft_strlen(string) - 1;
	while (end > 0 && string[end])
	{
		i = 0;
		while (charset[i])
		{
			if (charset[i] == string[end])
				break ;
			i++;
		}
		if (!charset[i])
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		end;
	int		start;

	if (!s1 || !set)
		return (NULL);
	start = check_start(s1, set);
	end = check_end(s1, set);
	string = ft_substr(s1, start, end - start + 1);
	return (string);
}
