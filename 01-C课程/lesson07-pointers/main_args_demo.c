/* ============================================================
 *  main_args_demo.c —— main 也能"收参数"
 *
 *  以前写 int main(void): 括号里是 void, 表示"不要任何参数"
 *  现在写 int main(int argc, char *argv[]): 表示"我要收命令行参数"
 *
 *  运行方式(在终端里, 不是 Ctrl+Shift+B):
 *      .\main_args_demo.exe apple banana
 *
 *  argc = 你一共敲了几个"词" (程序名自己也算一个)
 *  argv = 这些词的字符串数组, argv[0] 永远是程序名
 * ============================================================ */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}
