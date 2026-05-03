/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:36 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/05/03 21:12:08 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	*vector(float x, float y, float z)
{
	float	*tuple;

	tuple = malloc(sizeof(float) * 4);
	if (!tuple)
		return (NULL);
	tuple[0] = x;
	tuple[1] = y;
	tuple[2] = z;
	tuple[3] = VECTOR;
	return (tuple);
}

float	*point(float x, float y, float z)
{
	float	*tuple;

	tuple = malloc(sizeof(float) * 4);
	if (!tuple)
		return (NULL);
	tuple[0] = x;
	tuple[1] = y;
	tuple[2] = z;
	tuple[3] = POINT;
	return (tuple);
}

float	*add(float *tuple_a, float *tuple_b)
{
	float	*new_tuple;
	int		i;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new_tuple[i] = tuple_a[i] + tuple_b[i];
		i++;
	}
	return (new_tuple);
}

float	*substract(float *tuple_a, float *tuple_b)
{
	float	*new_tuple;
	int		i;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new_tuple[i] = tuple_a[i] - tuple_b[i];
		i++;
	}
	return (new_tuple);
}

float	*negate(float *tuple)
{
	float	*new_tuple;
	int		i;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new_tuple[i] = -tuple[i];
		i++;
	}
	return (new_tuple);
}

float	*multiply(float *tuple, float scalar)
{
	float	*new_tuple;
	int		i;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new_tuple[i] = tuple[i] * scalar;
		i++;
	}
	return (new_tuple);
}

float	*divide(float *tuple, float divider)
{
	float	*new_tuple;
	int		i;

	new_tuple = malloc(sizeof(4));
	if (!new_tuple)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new_tuple[i] = tuple[i] / divider;
		i++;
	}
	return (new_tuple);
}

float	magnitude(float *tuple)
{
	float	magnitude;
	int		i;

	i = 0;
	magnitude = 0;
	while (i < 3)
	{
		magnitude += tuple[i] * tuple[i];
		i++;
	}
	magnitude = sqrtf(magnitude);
	return (magnitude);
}

void	print_tuple(float *tuple)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i == 3)
			printf("%f\n", tuple[i]);
		else
			printf("%f, ", tuple[i]);
		i++;
	}
}

void	check_tuple(float *tuple)
{
	if (tuple[3] == VECTOR)
		printf("Tuple is a vector\n");
	else if (tuple[3] == POINT)
		printf("Tuple is a point\n");
	else
		printf("Tuple is neither\n");
}

bool	equal(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	else
		return (false);
}

int	main(void)
{
	float	*tuple_a;
	//float	*tuple_b;
	//float	*tuple_c;
	float	magn;

	tuple_a = vector(5.3, 2.2, 1.3);
	//tuple_b = vector(2.5, 4.5, 3.1);
	magn = magnitude(tuple_a);
	//print_tuple(tuple_c);
	printf("magnitude = %f\n", magn);
	return (0);
}
