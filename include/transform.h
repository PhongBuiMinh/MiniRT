#ifndef TRANSFORM_H
# define TRANSFORM_H

#include "matrix.h"
#include "tuple.h"
#include <math.h>

t_matrix4	translation(double x, double y, double z);
t_matrix4	scaling(double x, double y, double z);
t_matrix4	rotation_x(double radians);
t_matrix4	rotation_y(double radians);
t_matrix4	rotation_z(double radians);
t_matrix4	shearing(double xy, double xz,
						double yx, double yz,
						double zx, double zy);

// Convenience: apply transform to point/vector
t_tuple		transform_point(t_matrix4 t, t_tuple p);
t_tuple		transform_vector(t_matrix4 t, t_tuple v);

#endif
