/* 类型不匹配演示：type_mismatch_demo.c
 * 看看格式符和变量类型对不上时会发生什么 */
#include <stdio.h>

int main(void)
{
    int a = 65;         /* 整数 65 */
    double d = 3.14;    /* 小数 3.14 */
    char c = 'A';       /* 字符 A */

    printf("--- 匹配的（正确用法）---\n");
    printf("a 用 %%d: %d\n", a);        /* 65 */
    printf("d 用 %%lf: %lf\n", d);      /* 3.140000 */
    printf("c 用 %%c: %c\n", c);        /* A */

    printf("\n--- 不匹配的（错误用法）---\n");
    printf("a 用 %%f: %f\n", a);        /* 整数当小数打印 → 乱码 */
    printf("d 用 %%d: %d\n", d);        /* 小数当整数打印 → 乱码 */

    printf("\n--- 有趣的例外：字符和整数 ---\n");
    printf("a=65 用 %%c: %c\n", a);     /* 65 按字符显示 → A */
    printf("c='A' 用 %%d: %d\n", c);    /* A 按整数显示 → 65 */

    return 0;
}
