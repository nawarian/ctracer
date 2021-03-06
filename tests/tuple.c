#include "tuple.h"
#include "utils/float.h"
#include <assert.h>

void test_tuple(void);
void test_is_point(void);
void test_is_vector(void);
void test_point(void);
void test_vector(void);
void test_vector_magnitude(void);
void test_vector_magnitude_normalized_equals_zero(void);
void test_vector_normalize(void);
void test_vector_cross(void);
void test_vector_zero(void);
void test_tuple_add(void);
void test_tuple_sub_point(void);
void test_tuple_sub_point_vector(void);
void test_tuple_sub_vector_vector(void);
void test_tuple_sub_vector_from_zero_vector(void);
void test_tuple_negate(void);
void test_tuple_mul_scalar(void);
void test_tuple_mul_fraction(void);
void test_tuple_div(void);
void test_tuple_dot(void);

int main(void)
{
    test_tuple();
    test_is_point();
    test_is_vector();
    test_point();
    test_vector();
    test_vector_magnitude();
    test_vector_magnitude_normalized_equals_zero();
    test_vector_normalize();
    test_vector_cross();
    test_vector_zero();
    test_tuple_add();
    test_tuple_sub_point();
    test_tuple_sub_point_vector();
    test_tuple_sub_vector_vector();
    test_tuple_sub_vector_from_zero_vector();
    test_tuple_negate();
    test_tuple_mul_scalar();
    test_tuple_mul_fraction();
    test_tuple_div();
    test_tuple_dot();

    return 0;
}

void test_tuple(void)
{
    tuple_t t = tuple(10.0, 5.0, 15.0, 1.0);

    assert(_fequals(t.x, 10.0));
    assert(_fequals(t.y, 5.0));
    assert(_fequals(t.z, 15.0));
    assert(_fequals(t.w, 1.0));
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

    assert(_fequals(p.x, comp.x));
    assert(_fequals(p.y, comp.y));
    assert(_fequals(p.z, comp.z));
    assert(_fequals(p.w, comp.w));
}

void test_vector(void)
{
    tuple_t v = vector(4, -4, 3);
    tuple_t comp = tuple(4, -4, 3, 0);

    assert(_fequals(v.x, comp.x));
    assert(_fequals(v.y, comp.y));
    assert(_fequals(v.z, comp.z));
    assert(_fequals(v.w, comp.w));
}

void test_vector_magnitude(void)
{
    assert(vector_magnitude(vector(1, 0, 0)) == 1);
    assert(vector_magnitude(vector(0, 1, 0)) == 1);
    assert(vector_magnitude(vector(0, 0, 1)) == 1);

    assert(vector_magnitude(vector(1, 2, 3)) == sqrtf(14));
    assert(vector_magnitude(vector(-1, -2, -3)) == sqrtf(14));
}

void test_vector_cross(void)
{
    tuple_t a = vector(1, 2, 3);
    tuple_t b = vector(2, 3, 4);

    tuple_t comp1 = vector(-1, 2, -1);
    tuple_t cross = vector_cross(a, b);

    assert(_fequals(cross.x, comp1.x));
    assert(_fequals(cross.y, comp1.y));
    assert(_fequals(cross.z, comp1.z));
    assert(_fequals(cross.w, comp1.w));

    tuple_t comp2 = vector(1, -2, 1);
    cross = vector_cross(b, a);

    assert(_fequals(cross.x, comp2.x));
    assert(_fequals(cross.y, comp2.y));
    assert(_fequals(cross.z, comp2.z));
    assert(_fequals(cross.w, comp2.w));
}

void test_vector_normalize(void)
{
    tuple_t vec = vector(4, 0, 0);

    tuple_t norm = vector_normalize(vec);
    tuple_t comp = vector(1, 0, 0);

    assert(_fequals(norm.x, comp.x));
    assert(_fequals(norm.y, comp.y));
    assert(_fequals(norm.z, comp.z));
    assert(_fequals(norm.w, comp.w));

    vec = vector(1, 2, 3);

    norm = vector_normalize(vec);
    comp = vector(0.26726, 0.53452, 0.80178);

    assert(_fequals(norm.x, comp.x));
    assert(_fequals(norm.y, comp.y));
    assert(_fequals(norm.z, comp.z));
    assert(_fequals(norm.w, comp.w));
}

void test_vector_magnitude_normalized_equals_zero(void)
{
    tuple_t vec = vector(1, 2, 3);
    tuple_t norm = vector_normalize(vec);

    assert(_fequals(vector_magnitude(norm), 1));
}

void test_vector_zero(void)
{
    tuple_t zero = vector_zero();
    tuple_t comp = vector(0, 0, 0);

    assert(_fequals(zero.x, comp.x));
    assert(_fequals(zero.y, comp.y));
    assert(_fequals(zero.z, comp.z));
    assert(_fequals(zero.w, comp.w));
}

void test_tuple_add(void)
{
    tuple_t a1 = tuple(3, -2, 5, 1);
    tuple_t a2 = tuple(-2, 3, 1, 0);

    tuple_t sum = tuple_add(a1, a2);
    tuple_t comp = tuple(1, 1, 6, 1);

    assert(_fequals(sum.x, comp.x));
    assert(_fequals(sum.y, comp.y));
    assert(_fequals(sum.z, comp.z));
    assert(_fequals(sum.w, comp.w));
}

void test_tuple_sub_point(void)
{
    tuple_t p1 = point(3, 2, 1);
    tuple_t p2 = point(5, 6, 7);

    tuple_t sub = tuple_sub(p1, p2);
    tuple_t comp = vector(-2, -4, -6);

    assert(_fequals(sub.x, comp.x));
    assert(_fequals(sub.y, comp.y));
    assert(_fequals(sub.z, comp.z));
    assert(_fequals(sub.w, comp.w));
}

void test_tuple_sub_point_vector(void)
{
    tuple_t p1 = point(3, 2, 1);
    tuple_t vec = vector(5, 6, 7);

    tuple_t sub = tuple_sub(p1, vec);
    tuple_t comp = point(-2, -4, -6);

    assert(_fequals(sub.x, comp.x));
    assert(_fequals(sub.y, comp.y));
    assert(_fequals(sub.z, comp.z));
    assert(_fequals(sub.w, comp.w));
}

void test_tuple_sub_vector_vector(void)
{
    tuple_t vec1 = vector(3, 2, 1);
    tuple_t vec2 = vector(5, 6, 7);

    tuple_t sub = tuple_sub(vec1, vec2);
    tuple_t comp = vector(-2, -4, -6);

    assert(_fequals(sub.x, comp.x));
    assert(_fequals(sub.y, comp.y));
    assert(_fequals(sub.z, comp.z));
    assert(_fequals(sub.w, comp.w));
}

void test_tuple_sub_vector_from_zero_vector(void)
{
    tuple_t zero = vector_zero();
    tuple_t vec = vector(1, -2, 3);

    tuple_t sub = tuple_sub(zero, vec);
    tuple_t comp = vector(-1, 2, -3);

    assert(_fequals(sub.x, comp.x));
    assert(_fequals(sub.y, comp.y));
    assert(_fequals(sub.z, comp.z));
    assert(_fequals(sub.w, comp.w));
}

void test_tuple_negate(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t minus_a = tuple_negate(a);
    tuple_t comp = tuple(-1, 2, -3, 4);

    assert(_fequals(minus_a.x, comp.x));
    assert(_fequals(minus_a.y, comp.y));
    assert(_fequals(minus_a.z, comp.z));
    assert(_fequals(minus_a.w, comp.w));
}

void test_tuple_mul_scalar(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t mul = tuple_mul(a, 3.5);
    tuple_t comp = tuple(3.5, -7, 10.5, -14);

    assert(_fequals(mul.x, comp.x));
    assert(_fequals(mul.y, comp.y));
    assert(_fequals(mul.z, comp.z));
    assert(_fequals(mul.w, comp.w));
}

void test_tuple_mul_fraction(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t mul = tuple_mul(a, 0.5);
    tuple_t comp = tuple(0.5, -1, 1.5, -2);

    assert(_fequals(mul.x, comp.x));
    assert(_fequals(mul.y, comp.y));
    assert(_fequals(mul.z, comp.z));
    assert(_fequals(mul.w, comp.w));
}

void test_tuple_div(void)
{
    tuple_t a = tuple(1, -2, 3, -4);

    tuple_t div = tuple_div(a, 2);
    tuple_t comp = tuple(0.5, -1, 1.5, -2);

    assert(_fequals(div.x, comp.x));
    assert(_fequals(div.y, comp.y));
    assert(_fequals(div.z, comp.z));
    assert(_fequals(div.w, comp.w));
}

void test_tuple_dot(void)
{
    tuple_t a = vector(1, 2, 3);
    tuple_t b = vector(2, 3, 4);

    assert(_fequals(tuple_dot(a, b), 20));
}
