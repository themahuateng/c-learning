#include <stdio.h>

int main(void)
{
    int birth_year = 2007;   // 改成你的出生年份
    int this_year  = 2026;   // 今年

    int age = this_year - birth_year;   // 算出年龄

    int month = 8;
    printf("My age is %d\n", age);

    printf("现在月份是 %d\n", month);
    return 0;
}