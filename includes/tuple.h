#ifndef TUPLE_H
# define TUPLE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

# define EPSILON 0.00001

// Constructors
t_tuple	tuple(double x, double y, double z, double w);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);

// Predicates
int		is_point(t_tuple a);
int		is_vector(t_tuple a);

// Comparisons
int		double_equal(double a, double b);
int		tuple_equal(t_tuple a, t_tuple b);

// Basic operations
t_tuple	add_tuple(t_tuple a, t_tuple b);
t_tuple	sub_tuple(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple a);
t_tuple	mul_tuple_scalar(t_tuple a, double s);
t_tuple	div_tuple_scalar(t_tuple a, double s);

// Vector operations
double	magnitude(t_tuple v);
t_tuple	normalize(t_tuple v);
double	dot(t_tuple a, t_tuple b);
t_tuple	cross(t_tuple a, t_tuple b);

#endif
