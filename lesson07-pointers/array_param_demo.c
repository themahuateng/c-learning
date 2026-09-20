/* 数组参数演示：array_param_demo.c
 * 重点：函数怎么"接收"数组、怎么"修改"main里的数组 */
#include <stdio.h>

/* 1. 给数组填值的函数：参数写 int arr[]（带方括号）*/
void fill(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;     /* 往数组里写值 */
    }
}

/* 2. 打印数组的函数 */
void show(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[5] = {0};       /* main 里的数组，初始全 0 */

    printf("调用前：");
    show(a, 5);           /* 调用：只写名字 a，不带 [] */

    fill(a, 5);           /* 调用 fill，试试数组变不变 */

    printf("调用后：");
    show(a, 5);

    return 0;
}
