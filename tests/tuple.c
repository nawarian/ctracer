#include "tuple.h"
#include <assert.h>

void test_tuple(void);
void test_is_point(void);
void test_is_vector(void);
void test_point(void);
void test_vector(void);
void test_tuple_add(void);
void test_tuple_sub_point(void);
void test_tuple_sub_point_vector(void);
void test_tuple_sub_vector_vector(void);
void test_vector_zero(void);
void test_tuple_sub_vector_from_zero_vector(void);
void test_tuple_negate(void);
void test_tuple_mul_scalar(void);
void test_tuple_mul_fraction(void);
void test_tuple_div(void);

int main(void)
{
    test_tuple();
    test_is_point();
    test_is_vector();
    test_point();
    test_vector();
    test_tuple_add();
    test_tuple_sub_point();
    test_tuple_sub_point_vector();
    test_tuple_sub_vector_vector();
    test_vector_zero();
    test_tuple_sub_vector_from_zero_vector();
    test_tuple_negate();
    test_tuple_mul_scalar();
    test_tuple_mul_fraction();
    test_tuple_div();

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

void test_tuple_add(void)
{
    tuple_t a1 = tuple(3, -2, 5, 1);
    tuple_t a2 = tuple(-2, 3, 1, 0);

    tuple_t sum = tuple_add(a1, a2);
    tuple_t comp = tuple(1, 1, 6, 1);

    assert(sum.x == comp.x);
    assert(sum.y == comp.y);
    assert(sum.z == comp.z);
    assert(sum.w == comp.w);
}

void test_tuple_sub_point(void)
{
    tuple_t p1 = point(3, 2, 1);
    tuple_t p2 = point(5, 6, 7);

    tuple_t sub = tuple_sub(p1, p2);
    tuple_t comp = vector(-2, -4, -6);

    assert(sub.x == comp.x);
    assert(sub.y == comp.y);
    assert(sub.z == comp.z);
    assert(sub.w == comp.w);
}

void test_tuple_sub_point_vector(void)
{
    tuple_t p1 = point(3, 2, 1);
    tuple_t vec = vector(5, 6, 7);

    tuple_t sub = tuple_sub(p1, vec);
    tuple_t comp = point(-2, -4, -6);

    assert(sub.x == comp.x);
    assert(sub.y == comp.y);
    assert(sub.z == comp.z);
    assert(sub.w == comp.w);
}

void test_tuple_sub_vector_vector(void)
{
    tuple_t vec1 = vector(3, 2, 1);
    tuple_t vec2 = vector(5, 6, 7);

    tuple_t sub = tuple_sub(vec1, vec2);
    tuple_t comp = vector(-2, -4, -6);

    assert(sub.x == comp.x);
    assert(sub.y == comp.y);
    assert(sub.z == comp.z);
    assert(sub.w == comp.w);
}

void test_vector_zero(void)
{
    tuple_t zero = vector_zero();
    tuple_t comp = vector(0, 0, 0);

    assert(zero.x == comp.x);
    assert(zero.y == comp.y);
    assert(zero.z == comp.z);
    assert(zero.w == comp.w);
}

void test_tuple_sub_vector_from_zero_vector(void)
{
    tuple_t zero = vector_zero();
    tuple_t vec = vector(1, -2, 3);

    tuple_t sub = tuple_sub(zero, vec);
    tuple_t comp = vector(-1, 2, -3);

    assert(sub.x == comp.x);
    assert(sub.y == comp.y);
    assert(sub.z == comp.z);
    assert(sub.w == comp.w);
}

void test_tuple_negate(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t minus_a = tuple_negate(a);
    tuple_t comp = tuple(-1, 2, -3, 4);

    assert(minus_a.x == comp.x);
    assert(minus_a.y == comp.y);
    assert(minus_a.z == comp.z);
    assert(minus_a.w == comp.w);
}

void test_tuple_mul_scalar(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t mul = tuple_mul(a, 3.5);
    tuple_t comp = tuple(3.5, -7, 10.5, -14);

    assert(mul.x == comp.x);
    assert(mul.y == comp.y);
    assert(mul.z == comp.z);
    assert(mul.w == comp.w);
}

void test_tuple_mul_fraction(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t mul = tuple_mul(a, 0.5);
    tuple_t comp = tuple(0.5, -1, 1.5, -2);

    assert(mul.x == comp.x);
    assert(mul.y == comp.y);
    assert(mul.z == comp.z);
    assert(mul.w == comp.w);
}

void test_tuple_div(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t div = tuple_div(a, 2);
    tuple_t comp = tuple(0.5, -1, 1.5, -2);

    assert(div.x == comp.x);
    assert(div.y == comp.y);
    assert(div.z == comp.z);
    assert(div.w == comp.w);
}
