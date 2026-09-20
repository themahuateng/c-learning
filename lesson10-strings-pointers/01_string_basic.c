/* ============================================================
 *  01_string_basic.c —— 第 10 课：字符串与指针 5 件事
 *
 *  1. char s[] 与 char *s 的区别
 *  2. 字符串名就是首地址
 *  3. 指针可以指向字符串中间
 *  4. 两种遍历写法（下标 / 指针）
 *  5. 字符指针数组 = 一串字符串
 * ============================================================ */

#include <stdio.h>

int main(void)
{
    char  s1[] = "hello";       /* 数组: 自己有格子, 可以改 */
    char *s2   = "world";       /* 指针: 指向常量, 不能改 */

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    /* 改数组的内容: 合法 */
    s1[0] = 'H';
    printf("把 s1[0] 改成 'H' 之后: s1 = %s\n", s1);

    /* 字符串名就是首地址 */
    printf("\ns1       = %p\n", (void *)s1);
    printf("&s1[0]   = %p\n", (void *)&s1[0]);

    /* 指针可以指向字符串中间 */
    char *p = s1 + 1;
    printf("\ns1 + 1 指向的位置, 从那里开始打印: %s\n", p);

    /* 两种遍历写法 */
    printf("\n下标法遍历: ");
    for (int i = 0; s1[i] != '\0'; i++) {
        printf("%c ", s1[i]);
    }
    printf("\n指针法遍历: ");
    for (char *q = s1; *q != '\0'; q++) {
        printf("%c ", *q);
    }
    printf("\n");

    /* 字符指针数组: 一串字符串 */
    char *names[] = {"Tom", "Jerry", "Spike"};
    printf("\n名字列表(字符指针数组):\n");
    for (int i = 0; i < 3; i++) {
        printf("  names[%d] = %s\n", i, names[i]);
    }

    return 0;
}
