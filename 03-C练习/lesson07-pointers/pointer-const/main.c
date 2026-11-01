#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;

    const int *p = &a;   /* 指向只读 int，p 可以换指向 */
    p = &b;              /* 可以 */
    /* *p = 30; */       /* 错：不能通过 p 改值 */

    int * const q = &a;  /* 指针本身只读，*q 可以改 */
    /* q = &b; */        /* 错：q 不能换指向 */
    *q = 30;             /* 可以 */

    const int * const r = &a;  /* 两边都只读 */
    /* r = &b; */              /* 错 */
    /* *r = 30; */             /* 错 */

    printf("a=%d b=%d *p=%d *q=%d *r=%d\n",
           a, b, *p, *q, *r);

    return 0;
}