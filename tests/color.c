#include "color.h"
#include "utils/float.h"
#include <assert.h>

void test_color(void);
void test_color_add(void);
void test_color_sub(void);
void test_color_mul(void);
void test_color_blend(void);

int main(void)
{
    test_color();
    test_color_add();
    test_color_sub();
    test_color_mul();
    test_color_blend();

    return 0;
}

void test_color(void)
{
    color_t c = color(-0.5, 0.4, 1.7);

    assert(_fequals(-0.5, c.red));
    assert(_fequals(0.4, c.green));
    assert(_fequals(1.7, c.blue));
}

void test_color_add(void)
{
    color_t c1 = color(0.9, 0.6, 0.75);
    color_t c2 = color(0.7, 0.1, 0.25);

    color_t sum = color_add(c1, c2);
    color_t comp = color(1.6, 0.7, 1.0);

    assert(_fequals(sum.red, comp.red));
    assert(_fequals(sum.green, comp.green));
    assert(_fequals(sum.blue, comp.blue));
}

void test_color_sub(void)
{
    color_t c1 = color(0.9, 0.6, 0.75);
    color_t c2 = color(0.7, 0.1, 0.25);

    color_t sub = color_sub(c1, c2);
    color_t comp = color(0.2, 0.5, 0.5);

    assert(_fequals(sub.red, comp.red));
    assert(_fequals(sub.green, comp.green));
    assert(_fequals(sub.blue, comp.blue));
}

void test_color_mul(void)
{
    color_t c = color(0.2, 0.3, 0.4);

    color_t mul = color_mul(c, 2);
    color_t comp = color(0.4, 0.6, 0.8);

    assert(_fequals(mul.red, comp.red));
    assert(_fequals(mul.green, comp.green));
    assert(_fequals(mul.blue, comp.blue));
}

void test_color_blend(void)
{
    color_t c1 = color(1, 0.2, 0.4);
    color_t c2 = color(0.9, 1, 0.1);

    color_t blended = color_blend(c1, c2);
    color_t comp = color(0.9, 0.2, 0.04);

    assert(_fequals(blended.red, comp.red));
    assert(_fequals(blended.green, comp.green));
    assert(_fequals(blended.blue, comp.blue));
}
