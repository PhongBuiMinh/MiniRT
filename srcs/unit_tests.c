/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:06:21 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/08 15:11:51 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/tests.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

/* ===========================
** comparison helpers
** =========================== */

int	tuple_equal(t_tuple a, t_tuple b)
{
	return (equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w,
			b.w));
}

int	matrix_equal(t_matrix a, t_matrix b)
{
	int	r;
	int	c;

	r = 0;
	while (r < a.rows)
	{
		c = 0;
		while (c < a.cols)
		{
			if (!equal(a.data[r][c], b.data[r][c]))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

/* ===========================
** assertion helper
** =========================== */

int	assert_tuple(char *name, t_tuple actual, t_tuple expected)
{
	if (tuple_equal(actual, expected))
		return (1);
	printf(RED "[FAIL] " RESET "%s\n", name);
	printf("Expected: ");
	print_tuple(expected);
	printf("Actual:   ");
	print_tuple(actual);
	return (0);
}

int	assert_matrix(char *name, t_matrix actual, t_matrix expected)
{
	int	r;
	int	c;

	if (matrix_equal(actual, expected))
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
	r = 0;
	while (r < actual.rows)
	{
		c = 0;
		while (c < actual.cols)
		{
			printf("%10.5f ", actual.data[r][c]);
			c++;
		}
		printf("\n");
		r++;
	}
	return (0);
}

/* ===========================
** MATRIX TESTS
** =========================== */

int	test_identity_matrix(void)
{
	t_matrix	a;
	t_matrix	id;

	a = init_ind_matrix(4, 4);
	id = init_matrix(4, 4);
	id.data[0][0] = 1;
	id.data[1][1] = 1;
	id.data[2][2] = 1;
	id.data[3][3] = 1;
	return (assert_matrix("identity_matrix", a, id));
}

int	test_matrix_multiply(void)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	expected;

	a = init_matrix(4, 4);
	b = init_matrix(4, 4);
	a.data[0][0] = 1;
	a.data[0][1] = 2;
	a.data[1][0] = 3;
	a.data[1][1] = 4;
	b.data[0][0] = 2;
	b.data[0][1] = 0;
	b.data[1][0] = 1;
	b.data[1][1] = 2;
	expected = init_matrix(4, 4);
	expected.data[0][0] = 4;
	expected.data[0][1] = 4;
	expected.data[1][0] = 10;
	expected.data[1][1] = 8;
	return (assert_matrix("matrix_multiply", multiply_matrices(a, b),
			expected));
}

int	test_matrix_tuple_mul(void)
{
	t_matrix	a;
	t_tuple		t;
	t_tuple		expected;

	a = scaling(2, 3, 4);
	t = point(-4, 6, 8);
	expected = point(-8, 18, 32);
	return (assert_tuple("matrix_tuple_mul", mat_apply(a, t), expected));
}

int	test_translation_point(void)
{
	t_matrix	tm;
	t_tuple		p;

	tm = translation(5, -3, 2);
	p = point(-3, 4, 5);
	return (assert_tuple("translation_point", mat_apply(tm, p), point(2, 1,
				7)));
}

int	test_translation_inverse(void)
{
	t_matrix	tm;
	t_tuple		p;

	tm = translation(5, -3, 2);
	p = point(-3, 4, 5);
	return (assert_tuple("translation_inverse", mat_apply(inversion(tm), p),
			point(-8, 7, 3)));
}

int	test_scaling_point(void)
{
	t_matrix	s;
	t_tuple		p;

	s = scaling(2, 3, 4);
	p = point(-4, 6, 8);
	return (assert_tuple("scaling_point", mat_apply(s, p), point(-8, 18, 32)));
}

int	test_scaling_vector(void)
{
	t_matrix	s;
	t_tuple		v;

	s = scaling(2, 3, 4);
	v = vector(-4, 6, 8);
	return (assert_tuple("scaling_vector", mat_apply(s, v), vector(-8, 18,
				32)));
}

int	test_scaling_inverse(void)
{
	t_matrix	s;
	t_tuple		v;

	s = scaling(2, 3, 4);
	v = vector(-4, 6, 8);
	return (assert_tuple("scaling_inverse", mat_apply(inversion(s), v),
			vector(-2, 2, 2)));
}

int	test_rotation_x(void)
{
	t_tuple	p;

	p = point(0, 1, 0);
	return (assert_tuple("rotation_x", mat_apply(rotation_x(PI / 4), p),
			point(0, sqrt(2) / 2, sqrt(2) / 2)));
}

int	test_rotation_x_inverse(void)
{
	t_tuple	p;

	p = point(0, 1, 0);
	return (assert_tuple("rotation_x_inverse", mat_apply(inversion(rotation_x(PI
						/ 4)), p), point(0, sqrt(2) / 2, -sqrt(2) / 2)));
}

int	test_rotation_y(void)
{
	t_tuple	p;

	p = point(0, 0, 1);
	return (assert_tuple("rotation_y", mat_apply(rotation_y(PI / 4), p),
			point(sqrt(2) / 2, 0, sqrt(2) / 2)));
}

int	test_rotation_z(void)
{
	t_tuple	p;

	p = point(0, 1, 0);
	return (assert_tuple("rotation_z", mat_apply(rotation_z(PI / 4), p),
			point(-sqrt(2) / 2, sqrt(2) / 2, 0)));
}

int	test_shearing_xy(void)
{
	t_tuple			p;
	struct s_shear	sh;

	sh.xy = 1;
	sh.xz = 0;
	sh.yx = 0;
	sh.yz = 0;
	sh.zx = 0;
	sh.zy = 0;
	p = point(2, 3, 4);
	return (assert_tuple("shearing_xy", mat_apply(shearing(sh), p), point(5, 3,
				4)));
}

int	test_matrix_inverse(void)
{
	t_matrix	m;
	t_matrix	inv;
	t_matrix	id;

	m = init_matrix(4, 4);
	m.data[0][0] = 8;
	m.data[0][1] = -5;
	m.data[0][2] = 9;
	m.data[0][3] = 2;
	m.data[1][0] = 7;
	m.data[1][1] = 5;
	m.data[1][2] = 6;
	m.data[1][3] = 1;
	m.data[2][0] = -6;
	m.data[2][1] = 0;
	m.data[2][2] = 9;
	m.data[2][3] = 6;
	m.data[3][0] = -3;
	m.data[3][1] = 0;
	m.data[3][2] = -9;
	m.data[3][3] = -4;
	inv = inversion(m);
	id = multiply_matrices(m, inv);
	return (assert_matrix("matrix_inverse_identity", id, init_ind_matrix(4,
				4)));
}

/* ===========================
** LIGHTING TESTS
** =========================== */

int	test_lighting_eye_between_light_and_surface(void)
{
	t_shade	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, 0, -1);
	shade.normalv = vector(0, 0, -1);
	shade.light = point_light(point(0, 0, -10), color(1, 1, 1));
	result = lighting(shade);
	return (assert_tuple("lighting_eye_between_light_and_surface", result,
			color(1.9, 1.9, 1.9)));
}

int	test_lighting_eye_offset_45(void)
{
	t_shade	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	shade.normalv = vector(0, 0, -1);
	shade.light = point_light(point(0, 0, -10), color(1, 1, 1));
	result = lighting(shade);
	return (assert_tuple("lighting_eye_offset_45", result, color(1, 1, 1)));
}

int	test_lighting_light_offset_45(void)
{
	t_shade	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, 0, -1);
	shade.normalv = vector(0, 0, -1);
	shade.light = point_light(point(0, 10, -10), color(1, 1, 1));
	result = lighting(shade);
	return (assert_tuple("lighting_light_offset_45", result, color(0.7364,
				0.7364, 0.7364)));
}

int	test_lighting_eye_in_reflection_path(void)
{
	t_shade	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	shade.normalv = vector(0, 0, -1);
	shade.light = point_light(point(0, 10, -10), color(1, 1, 1));
	result = lighting(shade);
	return (assert_tuple("lighting_eye_in_reflection_path", result,
			color(1.6364, 1.6364, 1.6364)));
}

int	test_lighting_light_behind_surface(void)
{
	t_shade	shade;
	t_tuple	result;

	shade.m = material();
	shade.p = point(0, 0, 0);
	shade.eyev = vector(0, 0, -1);
	shade.normalv = vector(0, 0, -1);
	shade.light = point_light(point(0, 0, 10), color(1, 1, 1));
	result = lighting(shade);
	return (assert_tuple("lighting_light_behind_surface", result, color(0.1,
				0.1, 0.1)));
}

/* ===========================
** NORMAL TESTS
** =========================== */

int	test_normal_x_axis(void)
{
	t_sphere	s;

	s = sphere(1);
	return (assert_tuple("normal_x_axis", normal_at(s, point(1, 0, 0)),
			vector(1, 0, 0)));
}

int	test_normal_nonaxial(void)
{
	t_sphere	s;
	double		v;

	s = sphere(1);
	v = sqrt(3) / 3;
	return (assert_tuple("normal_nonaxial", normal_at(s, point(v, v, v)),
			vector(v, v, v)));
}

int	test_normal_is_normalized(void)
{
	t_sphere	s;
	t_tuple		n;
	double		v;

	s = sphere(1);
	v = sqrt(3) / 3;
	n = normal_at(s, point(v, v, v));
	return (assert_tuple("normal_is_normalized", n, normalize(n)));
}

int	test_normal_translated_sphere(void)
{
	t_sphere	s;

	s = sphere(1);
	s.transformation = translation(0, 1, 0);
	return (assert_tuple("normal_translated_sphere", normal_at(s, point(0,
					1.70711, -0.70711)), vector(0, 0.70711, -0.70711)));
}

int	test_normal_scaled_rotated_sphere(void)
{
	t_sphere	s;
	double		v;

	s = sphere(1);
	s.transformation = multiply_matrices(scaling(1, 0.5, 1), rotation_z(PI
				/ 5));
	v = sqrt(2) / 2;
	return (assert_tuple("normal_scaled_rotated_sphere", normal_at(s, point(0,
					v, -v)), vector(0, 0.97014, -0.24254)));
}

/* ===========================
** RUNNER
** =========================== */

void	run_test(t_test test, int *passed, int *failed)
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

/* ===========================
** MAIN
** =========================== */

int	main(void)
{
	int	passed;
	int	failed;
	int	i;

	t_test tests[] = {{"lighting_eye_between_light_and_surface",
		test_lighting_eye_between_light_and_surface},
						{"lighting_eye_offset_45", test_lighting_eye_offset_45},
						{"lighting_light_offset_45",
							test_lighting_light_offset_45},
						{"lighting_eye_in_reflection_path",
							test_lighting_eye_in_reflection_path},
						{"lighting_light_behind_surface",
							test_lighting_light_behind_surface},
						{"normal_x_axis", test_normal_x_axis},
						{"normal_nonaxial", test_normal_nonaxial},
						{"normal_is_normalized", test_normal_is_normalized},
						{"normal_translated_sphere",
							test_normal_translated_sphere},
						{"normal_scaled_rotated_sphere",
							test_normal_scaled_rotated_sphere},
						/* ===========================
						** MATRIX / TRANSFORM TESTS
						** =========================== */
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
						{"matrix_inverse", test_matrix_inverse}};
	passed = 0;
	failed = 0;
	i = 0;
	while (i < (int)(sizeof(tests) / sizeof(tests[0])))
	{
		run_test(tests[i], &passed, &failed);
		i++;
	}
	printf("\n");
	printf(BLUE "Total: %d\n" RESET, (int)(sizeof(tests) / sizeof(tests[0])));
	printf(GREEN "Passed: %d\n" RESET, passed);
	printf(RED "Failed: %d\n" RESET, failed);
	return (failed != 0);
}
