/* (double) 强制类型转换演示：cast_demo.c */
#include <stdio.h>
int main(void)
{
    int a = 7, b = 2;   /* 两个整数 */

    /* 情况1：都不转 → 整数除法，小数被丢掉 */
    double q1 = a / b;
    printf("a / b           = %lf  (整数除法，丢了小数)\n", q1);

    /* 情况2：把 b 转成 double */
    double q2 = a / (double)b;
    printf("a / (double)b   = %lf  (正确)\n", q2);

    /* 情况3：把 a 转成 double，效果一样 */
    double q3 = (double)a / b;
    printf("(double)a / b   = %lf  (正确)\n", q3);

    /* 情况4：用带小数的字面量 */
    double q4 = a / 2.0;
    printf("a / 2.0         = %lf  (正确)\n", q4);

    return 0;
}
