/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_runner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:23:45 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 19:58:05 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"

/* ===========================
** comparison helpers
** =========================== */

int	assert_true(char *name, bool value)
{
	if (!value)
	{
		printf("FAIL: %s\n", name);
		return (0);
	}
	return (1);
}

int	assert_false(char *name, bool value)
{
	if (value)
	{
		printf("FAIL: %s\n", name);
		return (0);
	}
	return (1);
}

int	tuple_equal(t_tuple a, t_tuple b)
{
	return (equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z)
		&& equal(a.w, b.w));
}

/* ===========================
** assertion helpers
** =========================== */

int	assert_tuple(char *name, t_tuple actual, t_tuple expected)
{
	if (tuple_equal(actual, expected))
		return (1);
	printf(RED "[FAIL] " RESET "%s\n", name);
	printf("Expected: ");
	t_print(expected);
	printf("Actual:   ");
	t_print(actual);
	return (0);
}

int	assert_matrix(char *name, t_matrix actual, t_matrix expected)
{
	int	r;
	int	c;

	if (m_equal(actual, expected))
		return (1);
	printf(RED "[FAIL] " RESET "%s\n", name);
	printf("Expected:\n");
	r = 0;
	while (r < expected.rows)
	{
		c = 0;
		while (c < expected.cols)
		{
			printf("%10.5f ", expected.data[r][c]);
			c++;
		}
		printf("\n");
		r++;
	}
	printf("Actual:\n");
	r = -1;
	while (++r < actual.rows)
	{
		c = -1;
		while (++c < actual.cols)
			printf("%10.5f ", actual.data[r][c]);
		printf("\n");
	}
	return (0);
}

/* ===========================
** RUNNER & MAIN
** =========================== */

static void	run_test(t_test test, int *passed, int *failed)
{
	if (test.fn())
	{
		printf(GREEN "[PASS] " RESET "%s\n", test.name);
		(*passed)++;
	}
	else
	{
		printf(RED "[FAIL] " RESET "%s\n", test.name);
		(*failed)++;
	}
}

int	main(void)
{
	int				passed;
	int				failed;
	int				i;
	static t_test	tests[] = {
	{"lighting_eye_between_light_and_surface",
		test_lighting_eye_between_light_and_surface},
	{"lighting_eye_offset_45", test_lighting_eye_offset_45},
	{"lighting_light_offset_45", test_lighting_light_offset_45},
	{"lighting_eye_in_reflection_path", test_lighting_eye_in_reflection_path},
	{"lighting_light_behind_surface", test_lighting_light_behind_surface},
	{"test_shading_intersection", test_shading_intersection},
	{"test_shading_intersection_inside", test_shading_intersection_inside},
	{"normal_x_axis", test_normal_x_axis},
	{"normal_nonaxial", test_normal_nonaxial},
	{"normal_is_normalized", test_normal_is_normalized},
	{"normal_translated_sphere", test_normal_translated_sphere},
	{"normal_scaled_rotated_sphere", test_normal_scaled_rotated_sphere},
	{"cylinder_intersection", test_cylinder_intersection},
	{"cylinder_truncated_intersections", test_cylinder_truncated_intersections},
	{"cylinder_closed_caps_intersections", test_cylinder_closed_caps_intersections},
	{"cylinder_normal_at", test_cylinder_normal_at},
	{"identity_matrix", test_identity_matrix},
	{"matrix_multiply", test_matrix_multiply},
	{"matrix_tuple_mul", test_matrix_tuple_mul},
	{"translation_point", test_translation_point},
	{"translation_inverse", test_translation_inverse},
	{"scaling_point", test_scaling_point},
	{"scaling_vector", test_scaling_vector},
	{"scaling_inverse", test_scaling_inverse},
	{"rotation_x", test_rotation_x},
	{"rotation_x_inverse", test_rotation_x_inverse},
	{"rotation_y", test_rotation_y},
	{"rotation_z", test_rotation_z},
	{"shearing_xy", test_shearing_xy},
	{"matrix_inverse", test_matrix_inverse},
	{"test_view_transform_default_orientation", test_view_transform_default_orientation},
	{"test_view_transform_positive_z", test_view_transform_positive_z},
	{"test_view_transform_moves_world", test_view_transform_moves_world},
	{"test_view_transform_arbitrary", test_view_transform_arbitrary},
	{"test_ray_for_pixel_center", test_ray_for_pixel_center},
	{"test_ray_for_pixel_corner", test_ray_for_pixel_corner},
	{"test_ray_for_pixel_transformed_camera", test_ray_for_pixel_transformed_camera},
	{"test_no_shadow_nothing_collinear", test_no_shadow_nothing_collinear},
	{"test_shadow_object_between_point_and_light", test_shadow_object_between_point_and_light},
	{"test_no_shadow_object_behind_light", test_no_shadow_object_behind_light},
	{"test_no_shadow_object_behind_point", test_no_shadow_object_behind_point},
	};

	passed = 0;
	failed = 0;
	i = 0;
	while (i < (int)(sizeof(tests) / sizeof(tests[0])))
	{
		run_test(tests[i], &passed, &failed);
		i++;
	}
	printf("\n" BLUE "Total: %d\n" RESET, (int)(sizeof(tests) / sizeof(tests[0])));
	printf(GREEN "Passed: %d\n" RESET, passed);
	printf(RED "Failed: %d\n" RESET, failed);
	return (failed != 0);
}
