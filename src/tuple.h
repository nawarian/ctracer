#ifndef tuple_h
#define tuple_h

#include <stdbool.h>

typedef struct tuple_t {
    float x;
    float y;
    float z;
    float w;
} tuple_t;

tuple_t tuple(float x, float y, float z, float w);
tuple_t point(float x, float y, float z);

bool is_point(tuple_t t);
bool is_vector(tuple_t t);

tuple_t tuple_add(tuple_t t1, tuple_t t2);
tuple_t tuple_mul(tuple_t t, float factor);
tuple_t tuple_negate(tuple_t t);
tuple_t tuple_sub(tuple_t t1, tuple_t t2);

tuple_t vector(float x, float y, float z);
tuple_t vector_zero(void);

#endif
