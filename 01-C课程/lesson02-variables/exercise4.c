/*
 * 练习 4（思考题）：整数溢出
 *
 * 任务：猜猜 int 最大值 +1 会输出什么？再运行验证。
 * 提示：int 是 32 位；最大值是 2147483647
 */
#include <stdio.h>
#include <limits.h>   /* INT_MAX / INT_MIN 在这里定义 */

int main(void)
{
    int x = 2147483647;
    printf("int的最大值为:%d\n",x);
    /* 第1步：输出 x 的值 */
    int y;
    y = (x + 1);
    printf("int最大值+1:%d\n",y);
    /* 第2步：输出 x+1 的值（猜猜会发生什么？） */
    printf("int_max:%d  int_min:%d\n",INT_MAX,INT_MIN);

    /* 第3步（挑战）：用 %d 输出 INT_MAX 和 INT_MIN */

    return 0;
}
