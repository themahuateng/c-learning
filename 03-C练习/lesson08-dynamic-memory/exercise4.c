#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("输入数字个数: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("输入无效\n");
        return 1;
    }

    int *p = NULL;

    /*
     * TODO 1：向系统借 n 个 int 的空间。
     *
     * 需要计算：n 个 int 一共多少字节？
     */

     p = malloc(n * sizeof(int));
    /*
     * TODO 2：检查 malloc 是否失败。
     */
     if (p == NULL)
     {
        printf("内存分配失败");
        return 1;
     }

    /*
     * TODO 3：读入 n 个整数。
     *
     * 借来的内存可以像数组一样使用：
     * p[0]、p[1]、p[2] ...
     */
     for (int i = 0;i < n;i++)
     {
        scanf("%d",&p[i]);
     }

    /*
     * TODO 4：求最大值、最小值和总和。
     *
     * 注意：n 至少是 1，所以可以把 p[0] 当作初始最大值和最小值。
     */
     int max = p[0];
     for(int i = 0;i<n;i++)
     {
        if(p[i]>max)
        {
            max = p[i];
        }
     }
     printf("最大值为%d\n",max);

    int min = p[0];
     for(int i = 0;i<n;i++)
     {
        if(p[i]<min)
        {
            min = p[i];
        }
     }
     printf("最小值为%d\n",min);
     /* TODO 5：输出最大值、最小值和平均值。
     *
     * 平均值要保留两位小数。
     */

     int sum = 0;
     for (int i = 0;i<n;i++)
     {
        sum = sum + p[i];
     }
     printf("平均值为%.3f\n",(double)sum/n);
    /*
     * TODO 6：把借来的内存还回去，并把 p 置为 NULL。
     */
     free(p);
     p = NULL;

    return 0;
}
