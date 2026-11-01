/*
 * 数据类型对比演示：types_demo.c
 * 运行：Ctrl+Shift+B（当前文件）
 */

#include <stdio.h>

int main(void)
{
    printf("===== 1. int 和 小数 的区别 =====\n");
    int a = 7 / 2;              /* 整数除法，小数部分直接丢掉 */
    double b = 7 / 2.0;         /* 有小数参与，结果是小数 */
    printf("int  a = 7 / 2     = %d\n", a);   /* 输出 3 */
    printf("double b = 7 / 2.0 = %lf\n", b);  /* 输出 3.5 */

    printf("\n===== 2. float 和 double 的精度区别 =====\n");
    float  f = 1.0f / 3.0f;     /* float 只有约7位有效数字 */
    double d = 1.0 / 3.0;       /* double 有约15位有效数字 */
    printf("float  f = 1/3 = %.15f\n", f);   /* 后面会不准确 */
    printf("double d = 1/3 = %.15lf\n", d);  /* 更准确 */

    printf("\n===== 3. char 到底是什么 =====\n");
    char c = 'A';               /* 字符 A */
    printf("char c = '%c'\n", c);
    printf("其实 c 在电脑里存的是数字 %d\n", c);  /* A 的ASCII码=65 */

    printf("\n===== 4. 各类型占内存大小 =====\n");
    printf("int=%zu  float=%zu  double=%zu  char=%zu (字节)\n",
           sizeof(int), sizeof(float), sizeof(double), sizeof(char));

    return 0;
}
