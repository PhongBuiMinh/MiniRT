#ifndef RAY_H
# define RAY_H

#include "tuple.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

t_ray	ray(t_tuple origin, t_tuple direction);
t_tuple	ray_position(t_ray r, double t);

#endif
