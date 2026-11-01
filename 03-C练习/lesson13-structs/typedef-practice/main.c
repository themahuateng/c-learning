#include <stdio.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point point;
/* TODO 1：给 struct Point 起一个外号 Point */

int main(void)
{
    /* TODO 2：用 Point 创建一个变量 p，初始化为 {3, 4} */
    point p = {3,4};

    printf("p = (%d, %d)\n", p.x, p.y);

    return 0;
}