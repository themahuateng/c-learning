/* 例4.5 选择法：从大到小排序（课件版，已加清晰缩进） */
#include <stdio.h>
#define N 4

int main(void)
{
    int i, j, t, k, a[N];

    printf("Input %d numbers:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    printf("\n");

    for (i = 0; i < N - 1; i++)
    {
        k = i;

        for (j = i + 1; j < N; j++)
        {
            if (a[k] < a[j])
                k = j;
        }

        if (k != i)
        {
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }

    printf("The sorted numbers:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
