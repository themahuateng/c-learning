#include <stdio.h>

typedef union Number
{
    int i;
    float f;
} Number;

typedef struct Both
{
    int i;
    float f;
} Both;

int main(void)
{
    printf("%lld,%lld\n",sizeof (Number),sizeof(Both));
  
    Number n;
    Both b;

    n.i = 10;
    printf("n.i = %d\n", n.i);

    n.f = 3.14f;
    printf("n.f = %.2f\n", n.f);

    printf("sizeof(Number) = %zu\n", sizeof(Number));
    printf("sizeof(Both) = %zu\n", sizeof(Both));

    b.i = 10;
    b.f = 3.14f;
    printf("b.i = %d, b.f = %.2f\n", b.i, b.f);

    return 0;
}