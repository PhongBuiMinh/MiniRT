#ifndef INTERSECTION_H
# define INTERSECTION_H

#include "ray.h"
#include "sphere.h"

#define MAX_INTERSECTIONS 8

typedef struct  s_intersection
{
    double      t;
    t_sphere    *object;
}   t_intersection;

typedef struct s_intersections
{
    int             count;
    t_intersection  xs[MAX_INTERSECTIONS];
}   t_intersections;

void            intersections_clear(t_intersections *xs);
void            intersections_add(t_intersections *xs, double t, t_sphere *object);
t_intersection  *hit(t_intersections *xs);

/* ray-sphere intersections (Stage 2) */
void            sphere_intersect(const t_sphere *s, t_ray r, t_intersections *xs);

#endif