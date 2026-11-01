#include <stdio.h>

int main(void)
{
    int a, b;                     // 同时声明两个变量

    printf("Enter first number: ");
    scanf("%d", &a);              // 别忘了 & ！

    printf("Enter second number: ");
    scanf("%d", &b);

    int sum = a + b;
    int diff = a - b;
    int prod = a * b;
    double quot = a /(double)b;  // 转成小数，商才精确

    printf("sum = %d\n", sum);   // ← 故意留个小坑
    printf("diff = %d\n", diff);   // ← 你发现问题了吗？
    printf("prod = %d\n", prod);
    printf("quot = %.2f\n", quot);

    return 0;
}