#include <stdio.h>

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[] = {5, 2, 4, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);

    print_array(a, n);

    /*
     * 插入排序：
     * a[0] 先看作已经排好；
     * 从 i = 1 开始，把 a[i] 插入左边已经排好的部分。
     */
    for (int i = 1; i < n; i++)
    {
        int key = a[i];       /* 先保存当前要插入的数 */
        int j = i - 1;        /* 从当前数的左边开始比较 */

        /*
         * TODO 1：
         * 当 j 还没有越界，并且左边的数大于 key 时，
         * 把左边这个数向右挪一格。
         *
         * 这里需要自己写 while 循环。
         */

        /*
         * TODO 2：
         * 找到插入位置后，把 key 放回数组。
         */
    }

    print_array(a, n);
    return 0;
}
