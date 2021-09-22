#include "color.h"

color_t color(float red, float green, float blue)
{
    return (color_t) {
        red,
        green,
        blue
    };
}
