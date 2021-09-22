#ifndef _utils_float_h
#define _utils_float_h

#include <math.h>
#include <stdbool.h>

// float comparison helper function
bool _fequals(float f1, float f2)
{
    return fabsf(f1 - f2) < 0.00001;
}
#endif
