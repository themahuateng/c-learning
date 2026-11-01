#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(void)
{
    /*
     * TODO 1：
     * 声明一个函数指针 operation。
     */
     int (*operation)(int,int);
     /*
     * 它要能指向这种函数：
     * 接收两个 int，返回 int。
     *
     * 提示：
     * int (*operation)(int, int);
     */

     operation = add;
    /*
     * TODO 2：
     * 让 operation 指向 add。
     */

    /* TODO 3：用 operation 调用 add(8, 3)，打印结果。 */

    printf("%d\n",operation(8,3));
    /*
     * TODO 4：
     * 让 operation 改指向 sub。
     */

     operation = sub;
    /* TODO 5：用 operation 调用 sub(8, 3)，打印结果。 */

    printf("%d\n",operation(8,3));
    return 0;
}
