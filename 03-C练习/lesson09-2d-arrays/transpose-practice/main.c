#include <stdio.h>

#define N 3

int main(void)
{
    int a[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b[N][N] = {0};
    int i, j;

    printf("原矩阵:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    /* TODO: 你的核心代码写在这里
       要求：用两层循环遍历 a，把 a[i][j] 存到 b[j][i]
    */

    printf("转置后:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", b[i][j]);
        printf("\n");
    }

    return 0;
}