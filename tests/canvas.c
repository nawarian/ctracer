#include "../src/color.c" // required for color symbols
#include "canvas.h"
#include "utils/float.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_canvas(void);
void test_canvas_write(void);
void test_canvas_write_validation(void);
void test_canvas_to_ppm_header(void);
void test_canvas_to_ppm_pixels(void);

int main(void)
{
    test_canvas();
    test_canvas_write();
    test_canvas_write_validation();
    test_canvas_to_ppm_header();
    test_canvas_to_ppm_pixels();

    return 0;
}

void test_canvas(void)
{
    canvas_t c = canvas(10, 20);

    // assert size
    assert(c.width == 10);
    assert(c.height == 20);

    // test pixels are initialized with color(0, 0, 0)
    color_t pixel_color;
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 10; ++x) {
            pixel_color = canvas_color_at(c, x, y);

            assert(_fequals(pixel_color.red, 0.0));
            assert(_fequals(pixel_color.green, 0.0));
            assert(_fequals(pixel_color.blue, 0.0));
        }
    }

    canvas_free(&c);
}

void test_canvas_write(void)
{
    canvas_t c = canvas(10, 20);
    color_t red = color(1, 0, 0);

    canvas_write(c, 2, 3, red);

    color_t color_at = canvas_color_at(c, 2, 3);
    assert(_fequals(color_at.red, red.red));
    assert(_fequals(color_at.green, red.green));
    assert(_fequals(color_at.blue, red.blue));

    canvas_free(&c);
}

void test_canvas_write_validation(void)
{
    canvas_t c = canvas(10, 20);
    color_t red = color(1, 0, 0);

    assert(canvas_write(c, 0, 0, red));
    assert(!canvas_write(c, 11, 0, red));

    canvas_free(&c);
}

void test_canvas_to_ppm_header(void)
{
    FILE *tmp_file = tmpfile();
    char *line = NULL;
    size_t len = 0;

    canvas_t c = canvas(5, 3);
    assert(canvas_to_ppm(c, tmp_file));
    fseek(tmp_file, 0, SEEK_SET);

    getline(&line, &len, tmp_file);
    assert(strcmp("P3\n", line) == 0);

    getline(&line, &len, tmp_file);
    assert(strcmp("5 3\n", line) == 0);

    getline(&line, &len, tmp_file);
    assert(strcmp("255\n", line) == 0);

    fclose(tmp_file);
}

void test_canvas_to_ppm_pixels(void)
{
    FILE *tmp_file = tmpfile();
    char *line = NULL;
    size_t len = 0;

    canvas_t c = canvas(5, 3);
    color_t c1 = color(1.5, 0, 0),
            c2 = color(0, 0.5, 0),
            c3 = color(-0.5, 0, 1);

    canvas_write(c, 0, 0, c1);
    canvas_write(c, 2, 1, c2);
    canvas_write(c, 4, 2, c3);

    assert(canvas_to_ppm(c, tmp_file));
    fseek(tmp_file, 0, SEEK_SET);

    // Skip 3 lines
    for (int i = 0; i < 3; ++i) {
        getline(&line, &len, tmp_file);
    }

    getline(&line, &len, tmp_file);
    assert(strcmp("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n", line) == 0);

    getline(&line, &len, tmp_file);
    assert(strcmp("0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n", line) == 0);

    getline(&line, &len, tmp_file);
    assert(strcmp("0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n", line) == 0);

    fclose(tmp_file);
}
