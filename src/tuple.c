#include "tuple.h"
#include <stdbool.h>

tuple_t tuple(float x, float y, float z, float w)
{
    return (tuple_t) { x, y, z, w };
}

bool is_point(tuple_t t)
{
    return t.w == 1.0;
}

bool is_vector(tuple_t t)
{
    return t.w == 0.0;
}
