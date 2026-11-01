/*
 * 第 1 课：第一个 C 程序
 * 作用：在屏幕上输出 "Hello, World!"
 *
 * 手动编译：gcc hello.c -o hello.exe
 * 手动运行：hello.exe（或 .\hello.exe）
 */

#include <stdio.h>   /* stdio.h 是"标准输入输出"头文件，printf 函数声明在这里 */

/* main 函数：程序的入口，程序从这一行开始执行 */
int main(void)
{
    /* printf 是"打印到屏幕"的函数；\n 表示换行 */
    printf("Hello, ccb!\n");
    printf("i am learning c!\n");
    /* return 0 表示程序正常结束（0 = 成功） */
    return 0;
}
