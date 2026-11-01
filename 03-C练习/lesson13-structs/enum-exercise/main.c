#include <stdio.h>

enum Weekday
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};
typedef enum Weekday x;
int main(void)
{
    /* TODO 1：创建一个 enum Weekday 变量 day，赋值为 WED */
    x day = WED;

    printf("day = %d\n", day);

    /* TODO 2：如果 day 等于 WED，打印 "星期三" */
    if(day == WED)
 {   printf("星期三\n") ;
 }
    return 0;
}