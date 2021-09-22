#include "canvas.h"
#include "color.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

canvas_t canvas(int width, int height)
{
    canvas_t canvas = { width, height, NULL };
    canvas.pixels = malloc(sizeof(color_t) * width * height);

    color_t black = color(0, 0, 0);
    for (int i = 0; i < width * height; ++i) {
        memcpy(canvas.pixels + i, &black, sizeof(black));
    }

    return canvas;
}

void canvas_free(canvas_t *canvas)
{
    free(canvas->pixels);
}

color_t canvas_color_at(canvas_t canvas, int x, int y)
{
    return canvas.pixels[x * y];
}

bool canvas_write(canvas_t canvas, int x, int y, color_t color)
{
    int idx = x * y;

    if (x > canvas.width - 1 || y > canvas.height - 1 || idx < 0) {
        // TODO: test the error reporting behaviour
        fprintf(
            stderr,
            "Warning: Pixel (%d,%d) is out of bounds (%d,%d)\n",
            x,
            y,
            canvas.width,
            canvas.height
        );
        return false;
    }

    memcpy(canvas.pixels + idx, &color, sizeof(color));
    return true;
}
