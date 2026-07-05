/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:24:06 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/03 21:27:02 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"

int	test_lighting_eye_between_light_and_surface(void)
{
	t_phong	phong;
	t_tuple	result;

	phong.in_shadow = false;
	phong.object.material = material();
	phong.point = point(0, 0, 0);
	phong.eyev = vector(0, 0, -1);
	phong.normalv = vector(0, 0, -1);
	phong.light = light_init(point(0, 0, -10), color(1, 1, 1));
	result = phong_lightning(phong);
	return (assert_tuple("lighting_eye_between_light_and_surface", result,
			color(1.9, 1.9, 1.9)));
}

int	test_lighting_eye_offset_45(void)
{
	t_phong	phong;
	t_tuple	result;

	phong.in_shadow = false;
	phong.object.material = material();
	phong.point = point(0, 0, 0);
	phong.eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	phong.normalv = vector(0, 0, -1);
	phong.light = light_init(point(0, 0, -10), color(1, 1, 1));
	result = phong_lightning(phong);
	return (assert_tuple("lighting_eye_offset_45", result, color(1, 1, 1)));
}

int	test_lighting_light_offset_45(void)
{
	t_phong	phong;
	t_tuple	result;

	phong.in_shadow = false;
	phong.object.material = material();
	phong.point = point(0, 0, 0);
	phong.eyev = vector(0, 0, -1);
	phong.normalv = vector(0, 0, -1);
	phong.light = light_init(point(0, 10, -10), color(1, 1, 1));
	result = phong_lightning(phong);
	return (assert_tuple("lighting_light_offset_45", result, color(0.7364,
				0.7364, 0.7364)));
}

int	test_lighting_eye_in_reflection_path(void)
{
	t_phong	phong;
	t_tuple	result;

	phong.in_shadow = false;
	phong.object.material = material();
	phong.point = point(0, 0, 0);
	phong.eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	phong.normalv = vector(0, 0, -1);
	phong.light = light_init(point(0, 10, -10), color(1, 1, 1));
	result = phong_lightning(phong);
	return (assert_tuple("lighting_eye_in_reflection_path", result,
			color(1.6364, 1.6364, 1.6364)));
}

int	test_lighting_light_behind_surface(void)
{
	t_phong	phong;
	t_tuple	result;

	phong.in_shadow = false;
	phong.object.material = material();
	phong.point = point(0, 0, 0);
	phong.eyev = vector(0, 0, -1);
	phong.normalv = vector(0, 0, -1);
	phong.light = light_init(point(0, 0, 10), color(1, 1, 1));
	result = phong_lightning(phong);
	return (assert_tuple("lighting_light_behind_surface", result, color(0.1,
				0.1, 0.1)));
}

int	test_shading_intersection(void)
{
	t_world			world;
	t_intersections	xs;
	t_phong			phong;
	t_tuple			actual;
	t_tuple			expected;
	int				result;

	world = world_default();

	xs = intersect(
			world.objects[0],
			r_init(point(0, 0, -5),
			vector(0, 0, 1)));

	if (xs.err)
		return (free(world.objects), false);

	phong = phong_computations(hit(xs),
			r_init(point(0, 0, -5),
			vector(0, 0, 1)));

	phong.light = world.light;

	actual = phong_lightning(phong);
	expected = color(0.38066, 0.47583, 0.28550);

	result = tuple_equal(actual, expected);

	free(xs.intersections);
	free(world.objects);

	return (result);
}

int	test_shading_intersection_inside(void)
{
	t_world			world;
	t_intersections	xs;
	t_phong			phong;
	t_tuple			actual;
	t_tuple			expected;
	int				result;
	t_ray			ray;

	world = world_default();

	world.light = light_init(
			point(0, 0.25, 0),
			color(1, 1, 1));

	ray = r_init(
			point(0, 0, 0),
			vector(0, 0, 1));

	xs = intersect(world.objects[1], ray);

	if (xs.err)
		return (free(world.objects), false);

	phong = phong_computations(
			hit(xs),
			ray);

	phong.light = world.light;

	actual = phong_lightning(phong);
	expected = color(0.90498, 0.90498, 0.90498);

	result = tuple_equal(actual, expected);

	free(xs.intersections);
	free(world.objects);

	return (result);
}
