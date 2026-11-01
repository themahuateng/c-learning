/*
 * 练习 1：判断奇偶数
 *
 * 任务：用户输入一个整数，程序输出它是奇数还是偶数
 * 提示：偶数能被 2 整除，即  n % 2 == 0
 */
#include <stdio.h>

int main(void)
{
    int n;
    printf("请输入一个整数：");
    /* 第1步：提示用户输入 */
    scanf("%d",&n);
    /* 第2步：scanf 读取整数 */
     if (n % 2 == 0)
     {
       printf("偶数\n"); /* code */
     } else if (n % 2 == 1){
       printf("奇数\n"); /* code */
     }
     
     
    /* 第3步：if 判断 n % 2 == 0 则输出 even，否则输出 odd */

    return 0;
}
