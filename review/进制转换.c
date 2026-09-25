#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a;
     if ( scanf("%d", &a) != 1)
    {
        printf("error\n");
        return 1;
    }
    int b = a;
    int n = 0;
    int i = 0;
    if (a == 0)
    {
        printf("0\n");
        return 0;
    }
    else if (a < 0)
    {
        printf("error\n");
        return 1;
    }
    while (b>0)
    {
      n++;
      b = b / 2;
    }
    int *p=malloc(n*sizeof(int));
    if (p == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }

    while (a > 0)
    {
        p[i] = a % 2;  
        a = a / 2;         /* 去掉最低位 */
        i++;               /* 存到下一格 */
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", p[j]);
    }
    printf("\n");
    free(p);
    p = NULL;

    return 0;
}