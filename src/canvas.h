#ifndef _canvas_h
#define _canvas_h

#include "color.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct canvas_t {
    int width;
    int height;
    color_t *pixels;
} canvas_t;

canvas_t canvas(int width, int height);
void canvas_free(canvas_t *canvas);
color_t canvas_color_at(canvas_t canvas, int x, int y);
bool canvas_write(canvas_t canvas, int x, int y, color_t color);
bool canvas_to_ppm(canvas_t canvas, FILE *dst);

#endif
