/*
 * 练习 2：找最高分（擂台法）
 *
 * 任务：找出数组里最大的数并输出
 * 提示：先假设 scores[0] 最大，循环里发现更大的就替换
 */
#include <stdio.h>

int main(void)
{
    int scores[5] = {98, 85, 77, 90, 66};

    /* 第1步：假设最大值 = scores[0] */
    int max = scores[0];

    /* 第2步：for 循环从 i=1 开始，发现更大的就更新 */
    for (int i = 0; i < 5; i++)
    {
        if (scores[i] > max)
        {
           max = scores[i]; /* code */
        }
        /* code */
    }
    printf("最高分为：%d\n",max );

    /* 第3步：输出最高分 */

    return 0;
}
