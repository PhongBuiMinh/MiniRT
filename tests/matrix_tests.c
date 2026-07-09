/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:23:54 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/07/09 13:58:46 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"

int	test_identity_matrix(void)
{
	t_matrix	a;
	t_matrix	id;

	a = init_id_matrix(4, 4);
	id = m_init(4, 4);
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

	a = m_init(4, 4);
	b = m_init(4, 4);
	a.data[0][0] = 1;
	a.data[0][1] = 2;
	a.data[1][0] = 3;
	a.data[1][1] = 4;
	b.data[0][0] = 2;
	b.data[0][1] = 0;
	b.data[1][0] = 1;
	b.data[1][1] = 2;
	expected = m_init(4, 4);
	expected.data[0][0] = 4;
	expected.data[0][1] = 4;
	expected.data[1][0] = 10;
	expected.data[1][1] = 8;
	return (assert_matrix("matrix_multiply", m_multiply(a, b),
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
	return (assert_tuple("matrix_tuple_mul", m_apply(a, t), expected));
}

int	test_translation_point(void)
{
	t_matrix	tm;
	t_tuple		p;

	tm = translation(5, -3, 2);
	p = point(-3, 4, 5);
	return (assert_tuple("translation_point", m_apply(tm, p), point(2, 1,
				7)));
}

int	test_translation_inverse(void)
{
	t_matrix	tm;
	t_tuple		p;

	tm = translation(5, -3, 2);
	p = point(-3, 4, 5);
	return (assert_tuple("translation_inverse", m_apply(inversion(tm), p),
			point(-8, 7, 3)));
}

int	test_scaling_point(void)
{
	t_matrix	m;
	t_tuple		p;

	m = scaling(2, 3, 4);
	p = point(-4, 6, 8);
	return (assert_tuple("scaling_point", m_apply(m, p), point(-8, 18, 32)));
}

int	test_scaling_vector(void)
{
	t_matrix	m;
	t_tuple		v;

	m = scaling(2, 3, 4);
	v = vector(-4, 6, 8);
	return (assert_tuple("scaling_vector", m_apply(m, v), vector(-8, 18,
				32)));
}

int	test_scaling_inverse(void)
{
	t_matrix	m;
	t_tuple		v;

	m = scaling(2, 3, 4);
	v = vector(-4, 6, 8);
	return (assert_tuple("scaling_inverse", m_apply(inversion(m), v),
			vector(-2, 2, 2)));
}

int	test_rotation_x(void)
{
	t_tuple	p;

	p = point(0, 1, 0);
	return (assert_tuple("rotation_x", m_apply(rotation_x(PI / 4), p),
			point(0, sqrt(2) / 2, sqrt(2) / 2)));
}

int	test_rotation_x_inverse(void)
{
	t_tuple	p;

	p = point(0, 1, 0);
	return (assert_tuple("rotation_x_inverse", m_apply(inversion(rotation_x(PI
						/ 4)), p), point(0, sqrt(2) / 2, -sqrt(2) / 2)));
}

int	test_rotation_y(void)
{
	t_tuple	p;

	p = point(0, 0, 1);
	return (assert_tuple("rotation_y", m_apply(rotation_y(PI / 4), p),
			point(sqrt(2) / 2, 0, sqrt(2) / 2)));
}

int	test_rotation_z(void)
{
	t_tuple	p;

	p = point(0, 1, 0);
	return (assert_tuple("rotation_z", m_apply(rotation_z(PI / 4), p),
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
	return (assert_tuple("shearing_xy", m_apply(shearing(sh), p), point(5, 3,
				4)));
}

int	test_matrix_inverse(void)
{
	t_matrix	m;
	t_matrix	inv;
	t_matrix	id;

	m = m_init(4, 4);
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
	id = m_multiply(m, inv);
	return (assert_matrix("matrix_inverse_identity", id, init_id_matrix(4,
				4)));
}

int	test_normal_x_axis(void)
{
	t_object	*s;
	int		result;

	s = sphere_create(0);
	if (!s)
		return (0);
	result = assert_tuple("normal_x_axis", normal_at(s, point(1, 0, 0)),
			vector(1, 0, 0));
	return (result);
}

int	test_normal_nonaxial(void)
{
	t_object	*s;
	double		v;
	int		result;

	s = sphere_create(0);
	if (!s)
		return (0);
	v = sqrt(3) / 3;
	result = assert_tuple("normal_nonaxial", normal_at(s, point(v, v, v)),
			vector(v, v, v));
	return (result);
}

int	test_normal_is_normalized(void)
{
	t_object	*s;
	t_tuple		n;
	double		v;
	int		result;

	s = sphere_create(0);
	if (!s)
		return (0);
	v = sqrt(3) / 3;
	n = normal_at(s, point(v, v, v));
	result = assert_tuple("normal_is_normalized", n, normalize(n));
	return (result);
}

int	test_normal_translated_sphere(void)
{
	t_object	*s;
	int		result;

	s = sphere_create(0);
	if (!s)
		return (0);
	set_transformation(s, translation(0, 1, 0));
	result = assert_tuple("normal_translated_sphere", normal_at(s, point(0,
					1.70711, -0.70711)), vector(0, 0.70711, -0.70711));
	return (result);
}

int	test_normal_scaled_rotated_sphere(void)
{
	t_object	*s;
	double		v;
	int		result;

	s = sphere_create(0);
	if (!s)
		return (0);
	set_transformation(s, m_multiply(scaling(1, 0.5, 1), rotation_z(PI
				/ 5)));
	v = sqrt(2) / 2;
	result = assert_tuple("normal_scaled_rotated_sphere", normal_at(s, point(0,
					v, -v)), vector(0, 0.97014, -0.24254));
	return (result);
}

int	test_cylinder_intersection(void)
{
	t_object		*cylinder;
	t_intersections	xs;
	t_ray			ray;
	int			result;

	cylinder = cylinder_create(0);
	if (!cylinder)
		return (0);
	xs = xs_init();
	if (xs.err)
		return (0);
	ray = r_init(point(0, 0, -5), vector(0, 0, 1));
	intersect(cylinder, ray, &xs);
	result = assert_true("cylinder_intersections_count", xs.count == 2);
	if (!result)
		return (free(xs.intersections), 0);
	result = assert_true("cylinder_intersection_t1", equal(xs.intersections[0].t, 4));
	if (!result)
		return (free(xs.intersections), 0);
	result = assert_true("cylinder_intersection_t2", equal(xs.intersections[1].t, 6));
	free(xs.intersections);
	return (result);
}

int	test_cylinder_normal_at(void)
{
	t_object	*cylinder;
	int		result;

	cylinder = cylinder_create(0);
	if (!cylinder)
		return (0);
	result = assert_tuple("cylinder_normal_at", normal_at(cylinder,
				point(1, 0, 0)), vector(1, 0, 0));
	return (result);
}

int	test_view_transform_default_orientation(void)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	from = point(0, 0, 0);
	to = point(0, 0, -1);
	up = vector(0, 1, 0);
	return (assert_matrix("view_transform_default_orientation",
			view_transform(from, to, up),
			init_id_matrix(4, 4)));
}

int	test_view_transform_positive_z(void)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	from = point(0, 0, 0);
	to = point(0, 0, 1);
	up = vector(0, 1, 0);
	return (assert_matrix("view_transform_positive_z",
			view_transform(from, to, up),
			scaling(-1, 1, -1)));
}

int	test_view_transform_moves_world(void)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	from = point(0, 0, 8);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	return (assert_matrix("view_transform_moves_world",
			view_transform(from, to, up),
			translation(0, 0, -8)));
}

int	test_view_transform_arbitrary(void)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix	expected;

	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);

	expected = m_init(4, 4);
	expected.data[0][0] = -0.50709;
	expected.data[0][1] = 0.50709;
	expected.data[0][2] = 0.67612;
	expected.data[0][3] = -2.36643;

	expected.data[1][0] = 0.76772;
	expected.data[1][1] = 0.60609;
	expected.data[1][2] = 0.12122;
	expected.data[1][3] = -2.82843;

	expected.data[2][0] = -0.35857;
	expected.data[2][1] = 0.59761;
	expected.data[2][2] = -0.71714;
	expected.data[2][3] = 0.00000;

	expected.data[3][0] = 0.00000;
	expected.data[3][1] = 0.00000;
	expected.data[3][2] = 0.00000;
	expected.data[3][3] = 1.00000;

	return (assert_matrix("view_transform_arbitrary",
			view_transform(from, to, up),
			expected));
}


int	test_ray_for_pixel_center(void)
{
	t_camera	c;
	t_ray		r;

	c = camera_init(201, 101, PI / 2);
	r = ray_for_pixel(c, 100, 50);
	if (!assert_tuple("ray_for_pixel_center_origin",
			r.origin, point(0, 0, 0)))
		return (0);
	return (assert_tuple("ray_for_pixel_center_direction",
			r.direction, vector(0, 0, -1)));
}

int	test_ray_for_pixel_corner(void)
{
	t_camera	c;
	t_ray		r;

	c = camera_init(201, 101, PI / 2);
	r = ray_for_pixel(c, 0, 0);
	if (!assert_tuple("ray_for_pixel_corner_origin",
			r.origin, point(0, 0, 0)))
		return (0);
	return (assert_tuple("ray_for_pixel_corner_direction",
			r.direction,
			vector(0.66519, 0.33259, -0.66851)));
}

int	test_ray_for_pixel_transformed_camera(void)
{
	t_camera	c;
	t_ray		r;
	double		v;

	c = camera_init(201, 101, PI / 2);
	c.transform = m_multiply(rotation_y(PI / 4),
			translation(0, -2, 5));

	r = ray_for_pixel(c, 100, 50);

	if (!assert_tuple("ray_for_pixel_transformed_origin",
			r.origin, point(0, 2, -5)))
		return (0);

	v = sqrt(2) / 2;
	return (assert_tuple("ray_for_pixel_transformed_direction",
			r.direction,
			vector(v, 0, -v)));
}

int	test_no_shadow_nothing_collinear(void)
{
	t_world	w;
	t_tuple	p;

	w = world_default();
	p = point(0, 10, 0);
	return (assert_false("no_shadow_nothing_collinear",
			is_shadowed(w, p)));
}

int	test_shadow_object_between_point_and_light(void)
{
	t_world	w;
	t_tuple	p;

	w = world_default();
	p = point(10, -10, 10);
	return (assert_true("shadow_object_between_point_and_light",
			is_shadowed(w, p)));
}

int	test_no_shadow_object_behind_light(void)
{
	t_world	w;
	t_tuple	p;

	w = world_default();
	p = point(-20, 20, -20);
	return (assert_false("no_shadow_object_behind_light",
			is_shadowed(w, p)));
}

int	test_no_shadow_object_behind_point(void)
{
	t_world	w;
	t_tuple	p;

	w = world_default();
	p = point(-2, 2, -2);
	return (assert_false("no_shadow_object_behind_point",
			is_shadowed(w, p)));
}
