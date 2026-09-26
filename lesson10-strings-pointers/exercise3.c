/* ============================================================
 *  exercise3.c —— 第 10 课综合题：字符串反转
 *
 *  要求：输入一个字符串（不含空格），原地把它反过来，再打印。
 *
 *  例：
 *      输入  hello
 *      输出  olleh
 *
 *  这一题没有填空，全部自己写。
 *
 *  建议先想清楚三个问题（写在纸上或心里都行）：
 *    1. 怎么知道字符串有多长？
 *    2. 要交换哪两格？第一次换谁和谁？
 *    3. 换到什么时候停？为什么不是换到最后一格？
 *
 *  提示（卡住再看）：
 *    - 你已经写过 my_strlen，可以拿来求长度
 *    - 交换两个格子需要一个临时变量：tmp = a; a = b; b = tmp;
 *    - 用两个下标：一个从左往右，一个从右往左，往中间靠
 * ============================================================ */

#include <stdio.h>

/* 这里写 my_strlen（你已经写过，凭印象再来一遍） */
int my_strlen(  char *text)
{
    int i = 0;
    while(text[i] !='\0'){
        i++;
    }
return i;
}

/* 这里写 reverse 函数 */
void reverse(char *text)
{
    int len = my_strlen(text);
    int l = 0;
    int r = len-1;
    while(l<r){
        char a = text[l];
        text[l] = text[r];
        text[r] = a;

        l++;
        r--;

    }

}

int main(void)
{
    char text[100];

    printf("输入一个字符串: ");
    scanf("%s",text);
    /* 读入字符串（不含空格），用 scanf 的 %s */


    /* 调用 reverse */
    reverse(text);
    printf("反转后: %s\n", text);

    return 0;
}
