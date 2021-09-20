#include "tuple.h"
#include <stdbool.h>

tuple_t tuple(float x, float y, float z, float w)
{
    return (tuple_t) { x, y, z, w };
}

tuple_t point(float x, float y, float z)
{
    return (tuple_t) { x, y, z, 1.0 };
}

tuple_t vector(float x, float y, float z)
{
    return (tuple_t) { x, y, z, 0.0 };
}

bool is_point(tuple_t t)
{
    return t.w == 1.0;
}

bool is_vector(tuple_t t)
{
    return t.w == 0.0;
}
