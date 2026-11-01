/*
 * 第 6 课教学演示：function_demo.c
 * 重点：函数定义、调用、参数、返回值、递归
 */
#include <stdio.h>

/* ===== 1. 定义一个函数：返回两个数的和 ===== */
double add(double x, double y)
{
    return x + y;               /* return = 把结果"吐"出去 */
}

/* ===== 2. 无返回值的函数（void 类型）===== */
void say_hello(void)
{
    printf("Hello from function!\n");
}

/* ===== 3. 判断是否偶数（返回 1=真 / 0=假）===== */
int is_even(int n)
{
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

/* ===== 4. 递归：求阶乘 5! = 5*4*3*2*1 ===== */
int factorial(int n)
{
    if (n <= 1) {
        return 1;               /* 结束条件：不能再拆了 */
    }
    return n * factorial(n - 1); /* 函数调用自己（规模变小） */
}

int main(void)
{
    /* 调用函数：喂参数进去，接住返回值 */
    double r = add(3.5, 2.5);
    printf("add(3.5, 2.5) = %.2f\n", r);

    say_hello();

    printf("is_even(7) = %d\n", is_even(7));
    printf("is_even(8) = %d\n", is_even(8));

    printf("5! = %d\n", factorial(5));

    return 0;
}
