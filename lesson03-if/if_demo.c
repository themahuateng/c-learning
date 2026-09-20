/*
 * 第 3 课教学演示：if_demo.c
 * 重点：比较运算符、if/else、逻辑运算符
 */
#include <stdio.h>

int main(void)
{
    int score = 85;

    /* ===== 1. 比较运算：结果只有 真(1) / 假(0) ===== */
    printf("score = %d\n", score);
    printf("score > 60  ? %d\n", score > 60);    /* 1 = 真 */
    printf("score == 100? %d\n", score == 100);  /* 0 = 假 */

    /* ===== 2. if 单分支 ===== */
    if (score >= 60) {
        printf("Pass!\n");        /* 条件为真才执行 */
    }

    /* ===== 3. if-else 双分支 ===== */
    int age = 15;
    if (age >= 18) {
        printf("Adult\n");
    } else {
        printf("Minor\n");        /* 条件为假走这里 */
    }

    /* ===== 4. else if 多分支 ===== */
    if (score >= 90) {
        printf("Grade A\n");
    } else if (score >= 80) {
        printf("Grade B\n");
    } else if (score >= 60) {
        printf("Grade C\n");
    } else {
        printf("Grade F\n");
    }

    /* ===== 5. 逻辑运算符 &&(且) ||(或) !(非) ===== */
    int hour = 22;
    if (hour >= 6 && hour <= 18) {   /* 6点到18点之间 */
        printf("Daytime\n");
    } else {
        printf("Night\n");
    }

    return 0;
}
