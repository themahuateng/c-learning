/* & 是什么：变量的"门牌号"（地址） */
#include <stdio.h>
int main(void)
{
    int a = 100;

    printf("a 的值   = %d\n", a);
    printf("a 的地址 = %p\n", &a);   /* %p 专门打印地址 */

    int b;
    printf("请输入一个数字: ");
    scanf("%d", &b);                 /* 带 &：把输入存到 b 的地址里 */
    printf("你输入的是: %d\n", b);

    return 0;
}
