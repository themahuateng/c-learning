/* ============================================================
 *  exercise2.c —— 第 10 课练习 2: 自己实现 my_strcpy
 *
 *  目标: 不用库函数, 把 src 的内容复制到 dst
 *        注意最后一定要补上 '\0'
 *
 *  留了 2 个空: ___HERE_1___ 和 ___HERE_2___
 *  提示都在注释里, 自己读, 自己想
 * ============================================================ */

#include <stdio.h>

void my_strcpy(char *dst, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        /* 空 1 ↓: 把 src 的这一格搬到 dst 的同一格 */
        dst[i] = src[i];
        i++;
    }
    
    

    /* 空 2 ↓: 复制完字符后, 还要补上字符串的结尾标记 */
    dst[i] = '\0';
}

int main(void)
{
    char src[] = "copy me";
    char dst[20];

    my_strcpy(dst, src);

    printf("原字符串:   %s\n", src);
    printf("复制的结果: %s\n", dst);

    return 0;
}
