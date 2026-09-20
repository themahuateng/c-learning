/*
 * 第 2 课：变量和数据类型
 * 编译运行：Ctrl+Shift+B（或 gcc variables.c -o variables.exe）
 */

#include <stdio.h>

#define PI 3.14159   /* #define 定义常量：编译时把 PI 替换成 3.14159 */

int main(void)
{
    /* 1. 声明变量：类型 名字 = 初始值; */
    int age = 20;             /* 整数类型 int */
    float height = 1.75f;     /* 单精度小数 float（数字后面加 f） */
    double pi = 3.1415926535; /* 双精度小数 double（更精确） */
    char grade = 'A';         /* 单个字符 char（用单引号） */

    /* 2. printf 输出：%d 整数，%f 小数，%c 字符 */
    printf("age = %d\n", age);
    printf("height = %.2f\n", height);   /* %.2f = 保留 2 位小数 */
    printf("pi = %.10lf\n", pi);         /* double 用 %lf */
    printf("grade = %c\n", grade);

    /* 3. scanf 从键盘输入：& 表示"取变量地址"，scanf 必须有它 */
    int yourAge;
    printf("Please enter your age: ");
    scanf("%d", &yourAge);
    printf("You entered: %d\n", yourAge);

    /* 4. 变量可以参与运算 */
    int nextYear = yourAge + 1;
    printf("Next year you will be %d.\n", nextYear);

    /* 5. const 常量：一旦赋值就不能再改 */
    const int WEEK_DAYS = 7;
    /* WEEK_DAYS = 8;  试试取消注释，会报错 */
    printf("A week has %d days.\n", WEEK_DAYS);

    /* 6. sizeof：查看类型占几个字节 */
    printf("int = %zu bytes, char = %zu bytes, double = %zu bytes\n",
           sizeof(int), sizeof(char), sizeof(double));

    return 0;
}
