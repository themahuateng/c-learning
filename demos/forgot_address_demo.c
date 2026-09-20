/* 忘了 & 会怎样（危险演示，仅作学习） */
#include <stdio.h>
int main(void)
{
    int a;               /* 没初始化，里面是随机垃圾值 */
    printf("请输入一个数字: ");
    scanf("%d", a);      /* ❌ 忘了 &，a 是垃圾值当地址用 */
    printf("你输入的是: %d\n", a);
    return 0;
}
