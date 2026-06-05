#ifndef SPHERE_H
# define SPHERE_H

#include "matrix.h"
#include "material.h"
#include "ray.h"

typedef struct  s_sphere
{
    t_matrix4   transform;
    t_matrix4   inverse;
    t_material  material;
}   t_sphere;

t_sphere    sphere_new(void);
void        sphere_set_transform(t_sphere *s, t_matrix4 t);
t_tuple     sphere_normal_at(const t_sphere *s, t_tuple world_point);

#endif