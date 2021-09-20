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

bool is_point(tuple_t t);
bool is_vector(tuple_t t);

#endif
