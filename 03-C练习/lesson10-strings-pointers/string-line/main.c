#include <stdio.h>

int main(void)
{
    char s[30];

    printf("请输入一行带空格的话: ");

    /* TODO: 用 fgets 从键盘读一行到 s，最多不超过 s 的大小 */
    fgets (s, sizeof(s), stdin);

    printf("你输入的是: %s", s);

    return 0;
}