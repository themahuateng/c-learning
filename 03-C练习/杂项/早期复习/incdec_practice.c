#include <stdio.h>

int main(void)
{
    int i = 5;

    int a = i++;
    int b = ++i;
    int c = -i++;
    int d = i--;
    int e = --i;

    /* TODO: 不要运行，先按顺序推演，把答案写在下面
       a = __5_
       b = 7___
       c = _-7__
       d = __8_
       e = _6__
       i = __6_
    */

    printf("%d %d %d %d %d %d\n", a, b, c, d, e, i);

    return 0;
}