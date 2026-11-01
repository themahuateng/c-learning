/* 星星三角形演示：star_demo.c
 * 放在第7课目录（明天学指针，这个先热身用）*/
#include <stdio.h>

int main(void)
{
    /* ===== 1. 你问的正三角：* ** *** **** ===== */
    printf("===== 正三角（4行）=====\n");
    for (int i = 1; i <= 4; i++) {        /* 外层：行，1~4 */
        for (int j = 1; j <= i; j++) {    /* 内层：每行 i 个星 */
            printf("*");
        }
        printf("\n");                     /* 换行 */
    }

    /* ===== 2. 倒三角：**** *** ** * ===== */
    printf("\n===== 倒三角（4行）=====\n");
    for (int i = 4; i >= 1; i--) {        /* 行从 4 往下 */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    /* ===== 3. 金字塔（加分题）===== */
    printf("\n===== 金字塔（4层）=====\n");
    for (int i = 1; i <= 4; i++) {
        for (int s = 1; s <= 4 - i; s++) {   /* 先打空格 */
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {  /* 再打星星 */
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
