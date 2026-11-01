/*
 * 练习 1：累加求和 1+2+3+...+100
 *
 * 任务：用循环算出 1 加到 100 的总和
 * 提示：答案是 5050（高斯小时候算过的）
 */
#include <stdio.h>

int main(void)
{
    int sum = 0;   /* 用来累加的和，初始为 0 */
    for (int i = 1; i <= 100; i++)
    {
        sum = sum + i;
    }
    printf("%d,\n",sum);
    

    /* 第1步：用 for 循环让 i 从 1 变到 100 */

    /* 第2步：每次把 i 加进 sum（sum = sum + i;） */

    /* 第3步：输出 sum */

    return 0;
}
