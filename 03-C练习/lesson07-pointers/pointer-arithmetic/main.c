#include <stdio.h>

int main(void)
{
    int a[] = {10, 20, 30, 40};
    int *p = a;

    printf("p     -> %d\n", *p);
    printf("p + 1 -> %d\n", *(p + 1));
    printf("p[2]  -> %d\n", p[2]);

    p++;
    printf("after p++, *p = %d\n", *p);

    int offset = (int)(p - a);
    printf("p - a = %d\n", offset);

    printf("sizeof(a) = %zu\n", sizeof(a));
    printf("sizeof(p) = %zu\n", sizeof(p));

    return 0;
}