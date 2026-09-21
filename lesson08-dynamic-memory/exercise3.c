/* ============================================================
 *  exercise3.c —— 第 8 课练习 3: 动态数组 + 函数（综合）
 *
 *  目标: 把第 7 课学的"数组作函数参数"和第 8 课的"动态内存"合起来
 *        读入和求平均都交给函数干
 *
 *  留了 2 个空: ___HERE_1___ 和 ___HERE_2___
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* 空 1 ↓: 补全读入函数 —— 往 p 里读 n 个数
 *   提示: 循环变量 i 已经有了, 这一行干的是"读入第 i 个数"
 */
void read_numbers(int *p, int n)
{
    for (int i = 0; i < n; i++) {
        ___HERE_1___
    }
}

double average(int *p, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i];
    }
    return sum / n;
}

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

    /* 空 2 ↓: 调用读入函数, 把借来的内存和个数交给它
     *   提示: 传数组时只写名字（第 7 课学的）
     */
    ___HERE_2___

    printf("平均 = %.2f\n", average(p, n));

    free(p);
    return 0;
}
