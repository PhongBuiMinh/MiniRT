#ifndef COLOR_H
# define COLOR_H

#include "tuple.h"

typedef struct s_color
{
    double  r;
    double  g;
    double  b;
}   t_color;

typedef struct s_canvas
{
    int     width;
    int     height;
    t_color *pixels;
}   t_canvas;

// Color operations
t_color color(double r, double g, double b);
t_color add_color(t_color a, t_color b);
t_color sub_color(t_color a, t_color b);
t_color mul_color_scalar(t_color c, double s);
t_color hadamard_color(t_color a, t_color b);

// Canvas operations
t_canvas canvas_new(int width, int height);
void     canvas_destroy(t_canvas *c);
void     write_pixel(t_canvas *c, int x, int y, t_color color);
t_color  pixel_at(t_canvas *c, int x, int y);

// ppm
void     canvas_to_ppm(const t_canvas *c, const char *filename);

#endif
