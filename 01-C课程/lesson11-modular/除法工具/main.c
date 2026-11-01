#include <stdio.h>
#include "div.h"
int main (void)
{
    int a,b;
    printf("输入两个数字\n");
    scanf("%d,%d",&a,&b);
    int div = divide(a,b);
    int divy = remainder0(a,b);
    printf("商为%d\n余数为%d\n",div,divy);
    return 0;
}