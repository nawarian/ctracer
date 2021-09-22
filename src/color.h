#ifndef _color_h
#define _color_h

typedef struct color_t {
    float red;
    float green;
    float blue;
} color_t;

color_t color(float red, float green, float blue);
color_t color_add(color_t c1, color_t c2);
color_t color_sub(color_t c1, color_t c2);
color_t color_mul(color_t color, float multiplier);
color_t color_blend(color_t c1, color_t c2);

#endif
