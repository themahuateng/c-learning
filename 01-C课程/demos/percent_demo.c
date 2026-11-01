/* %% 和 %c 的区别演示 */
#include <stdio.h>
int main(void)
{
    char grade = 'A';

    printf("写法1  %%c: %c\n", grade);    /* 想打印文字"%c"，必须写%%c */
    printf("写法2  %c\n", grade);          /* 单个%c = 占位符 */
    printf("写法3  100%%\n");              /* 打印一个%号 */
    printf("写法4  %%%c\n", grade);        /* %% 打印%，%c 填值 → %A */

    return 0;
}
