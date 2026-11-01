/*
 * 练习 2：成绩等级（else if 链）
 *
 * 任务：输入成绩（0~100），输出等级
 * 规则：
 *   90~100  → A
 *   80~89   → B
 *   70~79   → C
 *   60~69   → D
 *   0~59    → F
 */
#include <stdio.h>

int main(void)
{
    int score;
    printf("请输入成绩：");
    /* 第1步：printf 提示用户输入成绩 */
    scanf("%d",&score);
    /* 第2步：scanf 读取成绩 */
    if (score >= 90)
    {
        printf("A\n");/* code */
    } else if (score >= 80)
    {
        printf("B\n");/* code */
    } else if (score >= 70)
    {
        printf("C\n");/* code */
    } else if (score >= 60)
    {
        printf("D\n");/* code */
    } else
    {
        printf("F\n");/* code */
    }
    
    
    
    
    
    

    /* 第3步：用 else if 链判断并输出等级 */

    return 0;
}
