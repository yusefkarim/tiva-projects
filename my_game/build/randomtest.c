#include <stdio.h>

unsigned int Random(unsigned long seed)
{
    seed = ((((1664525 * seed + 1013904223) % 4294967296) >> 24) % 2) + 1;
    if(seed > 0)
        return seed;
    else
        return 1;
}

int main(void)
{
    unsigned int r = Random(44242522);
    printf("%d", r);
}
