/* ============================================================
 *  exercise1.c —— 第 8 课练习: 输入 n, 动态开数组, 求平均
 *
 *  目标: 先问用户"要输入几个数", 再读入这些数, 打印平均值
 *        数组大小必须是运行时才知道的 n —— 这就是动态内存的用武之地
 *
 *  留了 3 个空: ___HERE_1___ 到 ___HERE_3___
 *  提示都在注释里, 自己读, 自己想
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("要输入几个数: ");
    scanf("%d", &n);

    /* 空 1 ↓: 借 n 个 int 的内存, 把首地址存进 p
     *   提示: malloc 要的是"字节数" —— n 个 int 是多大?
     */
    int *p = malloc(n * sizeof(int));

    if (p == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    /* 读入 n 个数 */
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    /* 空 2 ↓: 把 p[i] 累加进 sum
     *   提示: 一个累加语句
     */
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + p[i];
    }

    printf("总和 = %.0f, 平均 = %.2f\n", sum, sum / n);

    /* 空 3 ↓: 用完了, 把内存还回去
     *   提示: 一个函数名 + 括号里的参数
     */
    free(p);

    return 0;
}
