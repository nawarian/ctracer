#include "color.h"

color_t color(float red, float green, float blue)
{
    return (color_t) {
        red,
        green,
        blue
    };
}

color_t color_add(color_t c1, color_t c2)
{
    return (color_t) {
        c1.red + c2.red,
        c1.green + c2.green,
        c1.blue + c2.blue
    };
}

color_t color_sub(color_t c1, color_t c2)
{
    return (color_t) {
        c1.red - c2.red,
        c1.green - c2.green,
        c1.blue - c2.blue
    };
}

color_t color_mul(color_t color, float multiplier)
{
    return (color_t) {
        multiplier * color.red,
        multiplier * color.green,
        multiplier * color.blue
    };
}
