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

bool is_point(tuple_t t)
{
    return t.w == 1.0;
}

bool is_vector(tuple_t t)
{
    return t.w == 0.0;
}

tuple_t tuple_add(tuple_t t1, tuple_t t2)
{
    return (tuple_t) {
        t1.x + t2.x,
        t1.y + t2.y,
        t1.z + t2.z,
        t1.w + t2.w
    };
}

tuple_t tuple_negate(tuple_t t)
{
    return (tuple_t) {
        -t.x,
        -t.y,
        -t.z,
        -t.w
    };
}

tuple_t tuple_sub(tuple_t t1, tuple_t t2)
{
    return (tuple_t) {
        t1.x - t2.x,
        t1.y - t2.y,
        t1.z - t2.z,
        t1.w - t2.w
    };
}

tuple_t vector(float x, float y, float z)
{
    return (tuple_t) { x, y, z, 0.0 };
}

tuple_t vector_zero(void)
{
    return vector(0, 0, 0);
}
