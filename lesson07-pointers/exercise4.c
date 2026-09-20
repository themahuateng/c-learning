/* ============================================================
 *  exercise4.c —— main 的参数
 *
 *  怎么跑 (在 VS Code 终端里, 不是 Ctrl+Shift+B):
 *      先用 Ctrl+Shift+B 编译一次, 然后终端里敲:
 *      .\exercise4.exe apple banana
 *
 *  留了 2 个空: ___HERE_1___ 和 ___HERE_2___
 *  提示都在注释里, 自己读, 自己想
 * ============================================================ */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* 空 1 ↓: 打印"一共收几个词" —— 哪个变量装着这个个数? */
    printf("argc = %d\n",argc );

    /* 空 2 ↓: 打印第 1 个真正参数 (程序名之后的第一个)
     *   argc 的规则是 argv[0] = 程序名, 所以第一个真正参数在 argv 的哪一格?
     */
    if (argc > 1) {
        printf("argv[1] = %s\n", argv[1]);
    } else {
        printf("你没敲参数\n");
    }

    return 0;
}
