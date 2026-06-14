/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:17:56 by bpetrovi          #+#    #+#             */
/*   Updated: 2026/06/14 19:27:52 by bpetrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <math.h>
# include "minirt.h"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

# ifndef PI
#  define PI 3.14159265358979323846
# endif

typedef struct s_test
{
	char	*name;
	int		(*fn)(void);
}	t_test;

/* ===========================
** Assertion & Comparison Helpers
** =========================== */
int	tuple_equal(t_tuple a, t_tuple b);
int	matrix_equal(t_matrix a, t_matrix b);
int	assert_tuple(char *name, t_tuple actual, t_tuple expected);
int	assert_matrix(char *name, t_matrix actual, t_matrix expected);

/* ===========================
** Matrix & Normal Tests
** =========================== */
int	test_identity_matrix(void);
int	test_matrix_multiply(void);
int	test_matrix_tuple_mul(void);
int	test_translation_point(void);
int	test_translation_inverse(void);
int	test_scaling_point(void);
int	test_scaling_vector(void);
int	test_scaling_inverse(void);
int	test_rotation_x(void);
int	test_rotation_x_inverse(void);
int	test_rotation_y(void);
int	test_rotation_z(void);
int	test_shearing_xy(void);
int	test_matrix_inverse(void);
int	test_normal_x_axis(void);
int	test_normal_nonaxial(void);
int	test_normal_is_normalized(void);
int	test_normal_translated_sphere(void);
int	test_normal_scaled_rotated_sphere(void);

/* ===========================
** phong_lightning Tests
** =========================== */
int	test_lighting_eye_between_light_and_surface(void);
int	test_lighting_eye_offset_45(void);
int	test_lighting_light_offset_45(void);
int	test_lighting_eye_in_reflection_path(void);
int	test_lighting_light_behind_surface(void);
int	test_shading_intersection(void);
int	test_shading_intersection_inside(void);

/* ===========================
** View Transformation Tests
** =========================== */

int	test_view_transform_default_orientation(void);
int	test_view_transform_positive_z(void);
int	test_view_transform_moves_world(void);
int	test_view_transform_arbitrary(void);

/* ===========================
** Ray Pixel Tests
** =========================== */

int	test_ray_for_pixel_center(void);
int	test_ray_for_pixel_corner(void);
int	test_ray_for_pixel_transformed_camera(void);

#endif