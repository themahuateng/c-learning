/* ============================================================
 *  01_malloc_basic.c —— 第 8 课：动态内存 4 件套
 *
 *  这一份要认的 4 样东西:
 *    1. malloc(n * sizeof(int))  —— 借一块能装 n 个 int 的内存
 *    2. if (p == NULL)           —— 借失败要检查
 *    3. p[i]                     —— 借来的内存, 当数组一样用
 *    4. free(p)                  —— 用完还回去
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>   /* malloc 和 free 在这个头文件里 */

int main(void)
{
    int n = 5;

    /* 借 5 个 int 那么大的内存 */
    int *p = malloc(n * sizeof(int));

    /* 借失败检查: 借不到时 malloc 返回 NULL */
    if (p == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    /* 借来的内存, 跟普通数组一样按下标用 */
    for (int i = 0; i < n; i++) {
        p[i] = (i + 1) * 10;
    }

    printf("借来的 %d 个格子: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    /* 还回去, 并把指针清空 */
    free(p);
    p = NULL;

    printf("已归还内存\n");
    return 0;
}
