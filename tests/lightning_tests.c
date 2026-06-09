/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* lighting_tests.c                                   :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/06/08 15:15:10 by bpetrovi          #+#    #+#             */
/* Updated: 2026/06/08 15:15:10 by bpetrovi         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "tests.h"

int	test_lighting_eye_between_light_and_surface(void)
{
	t_phong	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, 0, -1);
	shade.normalv = vector(0, 0, -1);
	shade.light = light_init(point(0, 0, -10), color(1, 1, 1));
	result = phong_lightning(shade);
	return (assert_tuple("lighting_eye_between_light_and_surface", result,
			color(1.9, 1.9, 1.9)));
}

int	test_lighting_eye_offset_45(void)
{
	t_phong	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	shade.normalv = vector(0, 0, -1);
	shade.light = light_init(point(0, 0, -10), color(1, 1, 1));
	result = phong_lightning(shade);
	return (assert_tuple("lighting_eye_offset_45", result, color(1, 1, 1)));
}

int	test_lighting_light_offset_45(void)
{
	t_phong	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, 0, -1);
	shade.normalv = vector(0, 0, -1);
	shade.light = light_init(point(0, 10, -10), color(1, 1, 1));
	result = phong_lightning(shade);
	return (assert_tuple("lighting_light_offset_45", result, color(0.7364,
				0.7364, 0.7364)));
}

int	test_lighting_eye_in_reflection_path(void)
{
	t_phong	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	shade.normalv = vector(0, 0, -1);
	shade.light = light_init(point(0, 10, -10), color(1, 1, 1));
	result = phong_lightning(shade);
	return (assert_tuple("lighting_eye_in_reflection_path", result,
			color(1.6364, 1.6364, 1.6364)));
}

int	test_lighting_light_behind_surface(void)
{
	t_phong	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, 0, -1);
	shade.normalv = vector(0, 0, -1);
	shade.light = light_init(point(0, 0, 10), color(1, 1, 1));
	result = phong_lightning(shade);
	return (assert_tuple("lighting_light_behind_surface", result, color(0.1,
				0.1, 0.1)));
}
