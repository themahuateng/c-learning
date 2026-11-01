/*
 * 第 4 课教学演示：loop_demo.c
 * 重点：while 循环、for 循环、break / continue
 */
#include <stdio.h>

int main(void)
{
    /* ===== 1. while 循环：先判断，再执行 ===== */
    int i = 1;
    while (i <= 5) {
        printf("while: %d\n", i);
        i = i + 1;          /* ★ 别忘了更新！不然死循环 */
    }

    /* ===== 2. for 循环：初始化; 条件; 更新 三合一 ===== */
    for (int j = 1; j <= 5; j++) {
        printf("for: %d\n", j);
    }

    /* ===== 3. break：提前跳出整个循环 ===== */
    for (int k = 1; k <= 10; k++) {
        if (k == 4) {
            break;          /* 到 4 就停，不再继续 */
        }
        printf("break test: %d\n", k);
    }

    /* ===== 4. continue：跳过本次，继续下一次 ===== */
    for (int m = 1; m <= 5; m++) {
        if (m == 3) {
            continue;       /* 跳过 3，继续 4、5 */
        }
        printf("continue test: %d\n", m);
    }

    return 0;
}
