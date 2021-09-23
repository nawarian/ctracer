#include "canvas.h"
#include "color.h"
#include <math.h>
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
    return canvas.pixels[x + (canvas.width * y)];
}

bool canvas_write(canvas_t canvas, int x, int y, color_t color)
{
    int idx = x + (canvas.width * y);

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

bool canvas_to_ppm(canvas_t canvas, FILE *dst)
{
    color_t pixel;
    int x = 0,
        y = 0,
        red = 0,
        green = 0,
        blue = 0;

    // Header
    fprintf(
        dst,
        "P3\n"
        "%d %d\n"
        "255\n",
        canvas.width,
        canvas.height
    );

    // Body
    for (y = 0; y < canvas.height; ++y) {
        for (x = 0; x < canvas.width; ++x) {
            pixel = canvas_color_at(canvas, x, y);
            red = (int) ceil(pixel.red * 255);
            red = red > 255 ? 255 : red;
            red = red < 0 ? 0 : red;

            green = (int) ceil(pixel.green * 255);
            green = green > 255 ? 255 : green;
            green = green < 0 ? 0 : green;

            blue = (int) ceil(pixel.blue * 255);
            blue = blue > 255 ? 255 : blue;
            blue = blue < 0 ? 0 : blue;

            fprintf(
                dst,
                "%d %d %d%s",
                red,
                green,
                blue,
                x + 1 == canvas.width ? "\n" : " "
            );
        }
    }

    return true;
}
