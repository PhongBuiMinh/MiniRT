/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:16:28 by bpetrovi          #+#    #+#             */
/*   Updated: 2025/04/11 22:24:53 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strdup_split(const char *s1, char c)
{
	size_t	i;
	size_t	a;
	char	*ptr;

	i = 0;
	a = 0;
	while (s1[i] && s1[i] != c)
		i++;
	ptr = malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (a < i)
	{
		ptr[a] = s1[a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}

static int	ft_find_len(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			counter++;
		else if (i > 0 && s[i] != c && s[i - 1] == c)
			counter++;
		i++;
	}
	return (counter);
}

static void	ft_freer(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		a;

	a = 0;
	i = 0;
	if (!s)
		return (NULL);
	array = malloc((ft_find_len(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			array[a] = ft_strdup_split(&s[i], c);
			if (!array[a])
				return (ft_freer(array, a), NULL);
			i += ft_strlen(array[a++]);
		}
		else
			i++;
	}
	array[a] = NULL;
	return (array);
}

// int main(void)
// {
// 	char c = 'c';
// 	char *hello = "Hellocmotherfuckerscyo";
// 	char **string;
// 	int i = 0;
// 	string = ft_split(hello, c);

// 	while(string[i])
// 	{
// 		printf("%s \n", string[i]);
// 		free(string[i]);
// 		i++;
// 	}
// 	free(string);
// }