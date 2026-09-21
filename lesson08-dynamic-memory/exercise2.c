/* ============================================================
 *  exercise2.c —— 第 8 课练习 2: 找最大最小值（动态数组版）
 *
 *  目标: 复用"借内存"那套流程, 这次练"擂台法"找最大最小
 *        做法: 先假设第一个是擂主, 后面的逐个挑战
 *
 *  留了 2 个空: ___HERE_1___ 和 ___HERE_2___
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("要输入几个数: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));
    if (p == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    /* 空 1 ↓: 擂台法的起点 —— 先让第 0 个数当擂主
     *   提示: 最大最小都先从哪一格开始?
     */
    int max = p[0];
    int min = p[0];

    /* 从第 1 个开始挑战 (第 0 个已经是擂主了) */
    for (int i = 1; i < n; i++) {
        if (p[i] > max) {
            /* 空 2 ↓: 有人打赢了, 换擂主 */
           max = p[i];
        }
        if (p[i] < min) {
            min = p[i];
        }
    }

    printf("最大 = %d, 最小 = %d\n", max, min);

    free(p);
    return 0;
}
