#include "tuple.h"
#include <assert.h>

void test_tuple(void);
void test_is_point(void);
void test_is_vector(void);
void test_point(void);
void test_vector(void);

int main(void)
{
    test_tuple();
    test_is_point();
    test_is_vector();
    test_point();
    test_vector();

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

void test_is_point(void)
{
    tuple_t t = tuple(4.3, -4.2, 3.1, 1.0);

    assert(is_point(t));
    assert(!is_vector(t));
}

void test_is_vector(void)
{
    tuple_t t = tuple(4.3, -4.2, 3.1, 0.0);

    assert(!is_point(t));
    assert(is_vector(t));
}

void test_point(void)
{
    tuple_t p = point(4, -4, 3);
    tuple_t comp = tuple(4, -4, 3, 1);

    assert(p.x == comp.x);
    assert(p.y == comp.y);
    assert(p.z == comp.z);
    assert(p.w == comp.w);
}

void test_vector(void)
{
    tuple_t v = vector(4, -4, 3);
    tuple_t comp = tuple(4, -4, 3, 0);

    assert(v.x == comp.x);
    assert(v.y == comp.y);
    assert(v.z == comp.z);
    assert(v.w == comp.w);
}
