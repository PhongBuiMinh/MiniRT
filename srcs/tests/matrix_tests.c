/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* matrix_tests.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/06/08 15:15:05 by bpetrovi          #+#    #+#             */
/* Updated: 2026/06/08 15:15:05 by bpetrovi         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../../includes/tests.h"

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