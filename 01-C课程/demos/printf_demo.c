/*
 * printf 格式符演示：printf_demo.c
 * 重点：printf 就像"填空题模板"，
 *       字符串里有几个 % 空位，后面就跟几个数据，按顺序填
 */

#include <stdio.h>

int main(void)
{
    int age = 20;          /* 整数变量 */
    double height = 1.75;  /* 小数变量 */
    char grade = 'A';      /* 字符变量 */

    /* 模板填空：字符串里有 3 个空（%d、%.1f、%c），
       后面跟 3 个数据（age、height、grade），按顺序一一对应 */
    printf("age=%d, height=%.1f, grade=%c\n", age, height, grade);

    /* 同一个变量，用不同的格式符，显示效果不同 */
    printf("grade as %%c: %c\n", grade);  /* %c = 按字符显示 → A */
    printf("grade as %%d: %d\n", grade);  /* %d = 按整数显示 → 65（字符背后的数字） */

    /* 小数保留位数由 .N 控制 */
    printf("height: %lf\n", height);   /* 不写 .N，默认输出 6 位小数 */
    printf("height: %.1f\n", height);  /* .1 = 保留 1 位小数 */
    printf("height: %.3f\n", height);  /* .3 = 保留 3 位小数 */

    return 0;
}
