#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "I love C";
    char *p = strstr(s, "love");

    if (p != NULL)
        printf("找到了: %.4s\n", p);
    else
        printf("没找到\n");

    return 0;
}