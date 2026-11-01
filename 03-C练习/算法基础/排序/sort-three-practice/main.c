#include <stdio.h>

#define N 6

int main(void)
{
    int bubble[N] = {5, 2, 4, 1, 3, 2};
    int selection[N] = {5, 2, 4, 1, 3, 2};
    int a[N] = {8, 8, 8, 8, 8, 8};
    printf("原始 bubble：   ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", bubble[i]);
    }
    printf("\n");

    printf("原始 selection：");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", selection[i]);
    }
    printf("\n");

    printf("原始 insertion：");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", bubble[i]);
    }
    printf("\n");
    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<5-i;j++)
        {
            if(bubble[j] > bubble[j+1])
            {
                int k = bubble[j];
                bubble[j] = bubble[j+1];
                bubble[j+1] = k;

            }

        }

    }//冒泡排序
    for(int i = 0; i<5;i++)
    {
         int min = i;
         for(int j = i+1;j<6;j++)
         {
             if (selection[j]<selection[min])
             {
                min = j;
             }
         }
         if (min != i)
         {
            int b = selection[i];
            selection[i] = selection[min];
            selection[min] = b;
         }

    }
    //选择排序
     for(int i = 1;i<6;i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j>=0 && a[j] > key )
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;

    }//插入排序
    

    printf("结果 bubble：   ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", bubble[i]);
    }
    printf("\n");

    printf("结果 selection：");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", selection[i]);
    }
    printf("\n");

    printf("结果 a：");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
