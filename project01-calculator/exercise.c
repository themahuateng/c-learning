/*
 * 阶段小项目：菜单计算器（第 1~4 课综合练习）
 *
 * 任务：补全代码，实现一个带菜单的计算器
 * 功能：
 *   1. 显示菜单（加法/减法/乘法/除法/退出）
 *   2. 用户选择后输入两个数，输出结果
 *   3. 除 0 要提示"不能除以 0"
 *   4. 输错选项要提示并回到菜单
 *   5. 选 0 退出程序
 */
#include <stdio.h>

int main(void)
{
    double a, b, result;
    int choice;

    while (1) {   /* 菜单循环：一直显示，直到选 0 退出 */
        /* ===== 菜单（已写好，不用改）===== */
        printf("\n===== Simple Calculator =====\n");
        printf("1. Add   2. Subtract\n");
        printf("3. Multiply  4. Divide\n");
        printf("0. Exit\n");
        printf("Your choice: ");

        /* 第3步：scanf 读取 choice（%d） */
        scanf("%d",&choice);

        /* 第4步：if (choice == 0) 输出 "Bye!" 并用 break 退出环 */
        if (choice == 0)
        {
           printf("Bye\n");
               break; /* code */
        } else if (choice == 1)
        {
            printf("请输入两个数\n");
            scanf("%lf",&a);
            scanf("%lf",&b);
            result = a + b;
            printf("%lf",result);/* code */
        } else if (choice == 2)
        {
            printf("请输入两个数\n");
            scanf("%lf",&a);
            scanf("%lf",&b);
            result = a - b;
            printf("%lf",result); /* code */
        }   else if (choice == 3)
        {
            printf("请输入两个数\n");
            scanf("%lf",&a);
            scanf("%lf",&b);
            result = a * b;
            printf("%lf",result); /* code */
        }   else if (choice == 4)
        {
            printf("请输入两个数\n");
            scanf("%lf",&a);
            scanf("%lf",&b);
            result = a / b;
            if (b == 0)
            {
               printf("error\n"); /* code */
            } else
            {
                printf("%lf",result);/* code */
            } 
            
            
            
            
        } else
        {
           printf("没有这个选项\n"); /* code */
        }
        
        
        
        
        
        

        /* 第5步：if (choice < 1 || choice > 4) 提示无效，用 continue 回到菜单 */

        /* 第6步：printf 提示输入两个数，scanf 读入 a 和 b（用 %lf %lf） */

        /* 第7步：else if 链判断 choice 是 1/2/3/4，算出结果并输出 */
    }

       return 0;
    }
