#include "tuple.h"
#include <assert.h>

void test_tuple(void);

int main(void)
{
    test_tuple();

    return 0;
}

void test_tuple(void)
{
    tuple_t t = tuple(10.0, 5.0, 15.0, 1.0);

    assert(t.x == 10.0);
    assert(t.y == 5.0);
    assert(t.z == 15.0);
    assert(t.w == 1.0);
}
