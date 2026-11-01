/*
 * 第 5 课教学演示：array_demo.c
 * 重点：一维数组、遍历、求平均、找最大、字符串
 */
#include <stdio.h>

int main(void)
{
    /* ===== 1. 什么是数组：一个名字，一排格子 ===== */
    int scores[5] = {98, 85, 77, 90, 66};
    /*              下标 [0] [1] [2] [3] [4]  ← 从 0 开始！ */

    printf("scores[0] = %d\n", scores[0]);   /* 第一个 = 98 */
    printf("scores[4] = %d\n", scores[4]);   /* 最后一个 = 66 */

    /* ===== 2. 遍历数组：for 循环挨个访问 ===== */
    printf("所有成绩：");
    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    /* ===== 3. 求平均分 ===== */
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + scores[i];
    }
    printf("平均分 = %.1f\n", sum / 5.0);

    /* ===== 4. 找最大值（擂台法）===== */
    int max = scores[0];           /* 先假设第一个最大 */
    for (int i = 1; i < 5; i++) {
        if (scores[i] > max) {     /* 发现更大的 */
            max = scores[i];       /* 就换上来 */
        }
    }
    printf("最高分 = %d\n", max);

    /* ===== 5. 字符串：本质是 char 数组 ===== */
    char name[20] = "Alice";       /* 末尾藏着结束符 \0 */
    printf("name = %s\n", name);   /* %s 打印整个字符串 */
    printf("第一个字母 = %c\n", name[0]);  /* 还是下标访问 */

    return 0;
}
