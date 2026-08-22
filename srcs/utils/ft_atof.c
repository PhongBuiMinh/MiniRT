/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 18:40:48 by fbui-min          #+#    #+#             */
/*   Updated: 2026/08/22 18:41:13 by fbui-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	skip_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static double	parse_fraction(const char *str, int *i)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result += (str[*i] - '0') * fraction;
		fraction *= 0.1;
		(*i)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	i = skip_sign(str, &sign);
	result = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		result += parse_fraction(str, &i);
	}
	result *= sign;
	if (result > FLT_MAX)
		return (FLT_MAX);
	if (result < -FLT_MAX)
		return (-FLT_MAX);
	return (result);
}
