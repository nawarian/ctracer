#include "color.h"
#include "utils/float.h"
#include <assert.h>

void test_color(void);

int main(void)
{
    test_color();
}

void test_color(void)
{
    color_t c = color(-0.5, 0.4, 1.7);

    assert(_fequals(-0.5, c.red));
    assert(_fequals(0.4, c.green));
    assert(_fequals(1.7, c.blue));
}
