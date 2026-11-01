#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

/*
 * calculate 不关心具体做加法还是减法。
 * 它只负责接收两个数和一个函数指针，然后调用传进来的函数。
 */
int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a,b);
}

int main(void)
{
    /*
     * TODO 2：调用 calculate(8, 3, add)，打印结果。
     * 期望：11
     */
     printf("%d\n",calculate(8,3,add));

    /*
     * TODO 3：调用 calculate(8, 3, sub)，打印结果。
     * 期望：5
     */

     printf("%d\n",calculate(8,3,sub));
    return 0;
}
