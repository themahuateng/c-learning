/*
 * 练习 3（挑战）：字符串逆序
 *
 * 任务：输入一个英文单词，逆序打印出来
 * 例：输入 hello → 输出 olleh
 *
 * 提示：
 *   - char word[50];
 *   - scanf("%s", word);        // 字符串不用加 &！
 *   - strlen(word) 得到长度     // 需要 #include <string.h>
 *   - 从最后一个字符往前打印
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[50];

    /* 第1步：提示输入，scanf("%s", word) 读单词 */
    printf("请输入要逆序的单词：");
    scanf("%s",word);

    /* 第2步：int len = strlen(word); 得到长度 */
    int len = strlen (word);
    for (int i = len-1 ; i >= 0; i--)
    {
        printf("%c",word[i]);/* code */
    }
    
    printf("\n");

    /* 第3步：for 循环从后往前打印（i = len-1 到 0） */

    return 0;
}
