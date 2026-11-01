/*
 * 练习 3：判断闰年（用到 && 和 ||）
 *
 * 任务：输入一个年份，输出它是不是闰年
 *
 * 闰年规则（二选一满足就是闰年）：
 *   ① 能被 4 整除，且不能被 100 整除
 *   ② 能被 400 整除
 *
 * 例子：2024 闰年 ✓   2023 不是 ✗   2000 闰年 ✓   1900 不是 ✗
 */
#include <stdio.h>

int main(void)
{
    int year;
    printf("请输入年份：");
    /* 第1步：提示用户输入年份 */
    scanf("%d",&year);

    /* 第2步：scanf 读取 */
    if ((year % 4 ==0 && year % 100 != 0) || (year % 400 ==0))
    {
        printf("%d是闰年\n",year);/* code */
    } else
    {
        printf("%d不是闰年\n",year);/* code */
    }
    
    

    /* 第3步：用 && 和 || 组合条件，if 判断并输出 */
    /*   is leap = (year%4==0 && year%100!=0) || (year%400==0)  */

    return 0;
}
