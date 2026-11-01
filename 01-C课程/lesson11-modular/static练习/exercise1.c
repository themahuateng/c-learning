/* ============================================================
 *  exercise1.c —— 第 11 课练习: static 的"长期记忆"
 *
 *  目标: 让 next_id() 每次调用返回 1、2、3……
 *        而 broken_id() 因为没有 static, 每次都从 0 开始
 *
 *  留了 2 个空: ___HERE_1___ 和 ___HERE_2___
 *  提示都在注释里, 自己读, 自己想
 * ============================================================ */

#include <stdio.h>

/* 空 1 ↓: 让 count 只初始化一次, 函数结束后值还留着
 *   提示: 一个关键字, 加在 int 前面
 */
int next_id(void)
{
    static int count = 0;
    count++;
    return count;
}

/* 对比: 没有那个关键字, 每次调用都重新从 0 开始 */
int broken_id(void)
{
    /* 空 2 ↓: 没有"长期记忆", 每次进来都从几开始数? */
    int count = 0;
    count++;
    return count;
}

int main(void)
{
    /* 注意: 分开写成单独语句, 不要塞进同一个 printf
     * 因为 C 不保证函数参数的求值顺序 (gcc 是从右往左算的)
     */
    int a = next_id();
    int b = next_id();
    int c = next_id();
    printf("next_id 连续调用三次:   %d %d %d\n", a, b, c);

    int x = broken_id();
    int y = broken_id();
    int z = broken_id();
    printf("broken_id 连续调用三次: %d %d %d\n", x, y, z);

    return 0;
}
