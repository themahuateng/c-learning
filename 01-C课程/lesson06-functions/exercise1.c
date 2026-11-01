/*
 * 练习 1：用函数重构计算器
 *
 * 任务：把计算器的 4 个运算写成函数
 *   1. 定义 4 个函数 add/sub/mul/divide（返回 double）
 *   2. main 里调用它们算结果
 *
 * 例：double add(double x, double y) { return x + y; }
 *
 * ★ 这就是你之前说"代码好臃肿"的终极解法！
 */
#include <stdio.h>

/* ===== 在这里定义 4 个函数 ===== */
double sub(double a,double b){
    return a - b;
}
double add(double a,double b){
    return a + b;
}
double mul(double a,double b){
    return a * b;
}
double divide(double a,double b){
    return a / b;
}
int main(void)
{
    double a = 3.5, b = 2.5;

    printf("%.2f + %.2f = %.2f\n", a, b, add(a, b));
    printf("%.2f - %.2f = %.2f\n", a, b, sub(a, b));
    printf("%.2f * %.2f = %.2f\n", a, b, mul(a, b));
    printf("%.2f / %.2f = %.2f\n", a, b, divide(a, b));

    return 0;
}
