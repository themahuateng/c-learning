/*
 * 练习 3（挑战）：递归求阶乘
 *
 * 任务：用递归写 int factorial(int n) = n!
 *
 * 规则：
 *   factorial(0) = 1
 *   factorial(1) = 1
 *   factorial(n) = n * factorial(n-1)
 *
 * 例：5! = 5*4*3*2*1 = 120
 *
 * 提示：回忆演示里的 factorial 写法（结束条件 + 调用自己）
 */
#include <stdio.h>

/* ===== 在这里写 factorial 函数（递归）===== */
int factorial(int n){
    if (n < 2)
    {
       return 1; /* code */
    }
    return n * factorial(n - 1) ;
}

int main(void)
{
    for (int i = 0; i <= 10; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }
    return 0;
}
