#ifndef LIGHT_H
# define LIGHT_H

#include "tuple.h"
#include "color.h"

typedef struct  s_point_light
{
    t_tuple position;
    t_color intensity;
}   t_point_light;

t_point_light   point_light(t_tuple position, t_color intensity);

#endif