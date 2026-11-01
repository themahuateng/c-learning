/*
 * 练习 1：输入 5 个成绩，求平均分
 *
 * 任务：
 *   1. 用 for 循环 + scanf 依次输入 5 个成绩（存进数组）
 *   2. 用 for 循环求和
 *   3. 输出平均分（保留 2 位小数）
 */
#include <stdio.h>

int main(void)
{
    int scores[5];
    double sum = 0;

    /* 第1步：for 循环 i 从 0 到 4，scanf("%d", &scores[i]) 读入 */
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&scores[i]);/* code */
        sum = sum + scores[i];
    }
    printf("%.2f", sum / 5.0);


    /* 第2步：for 循环求和（sum = sum + scores[i]） */

    /* 第3步：输出平均分（sum / 5.0，%.2f） */

    return 0;
}
