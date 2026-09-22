/* ============================================================
 *  exercise2.c —— 第 9 课练习 2: switch 与三目运算符（两个小补丁）
 *
 *  目标: 菜单选 1/2/3, 分别输出 较大值 / 较小值 / 和
 *
 *  留了 2 个空: ___HERE_1___ 和 ___HERE_2___
 *  提示都在注释里
 * ============================================================ */

#include <stdio.h>

int main(void)
{
    int a = 7;
    int b = 3;
    int choice;

    printf("1. 较大值   2. 较小值   3. 和\n");
    printf("你的选择: ");
    scanf("%d", &choice);

    /* 空 1 ↓: 用三目运算符, 一次算出 a 和 b 里较大的那个
     *   写法参考: (条件) ? 条件真时的值 : 条件假时的值
     */
    int bigger = ___HERE_1___;

    switch (choice) {
        case 1:
            printf("较大值 = %d\n", bigger);
            /* 空 2 ↓: 每个 case 干完活, 必须写一句什么?
             *   （不写的话, 会继续往下执行别的 case）
             */
            ___HERE_2___
        case 2:
            printf("较小值 = %d\n", (a < b) ? a : b);
            break;
        case 3:
            printf("和 = %d\n", a + b);
            break;
        default:
            printf("没有这个选项\n");
            break;
    }

    return 0;
}
