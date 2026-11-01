/* 循环慢镜头追踪：trace_demo.c
 * 看看 while / for 每一步发生了什么 */
#include <stdio.h>

int main(void)
{
    printf("========= while 慢镜头 =========\n");
    int i = 1;
    while (i <= 3) {
        printf("判断: %d <= 3 ? 真 → 执行\n", i);
        printf("  打印 i = %d\n", i);
        i = i + 1;
        printf("  更新后 i = %d\n", i);
    }
    printf("判断: %d <= 3 ? 假 → 退出循环\n", i);

    printf("\n========= for 慢镜头 =========\n");
    for (int j = 1; j <= 3; j++) {
        printf("j = %d，判断 %d <= 3 ? 真 → 执行，更新后 j = %d\n", j, j, j + 1);
    }
    printf("j = 4，判断 4 <= 3 ? 假 → 退出循环\n");

    printf("\n========= 累加过程（练习1的雏形）=========\n");
    int sum = 0;
    for (int k = 1; k <= 5; k++) {
        sum = sum + k;
        printf("第%d次: sum = %d + %d = %d\n", k, sum - k, k, sum);
    }
    printf("最终 sum = %d\n", sum);

    return 0;
}
