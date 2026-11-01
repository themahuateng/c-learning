#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_NAME 21

struct Student
{
    char name[MAX_NAME];
    int score;
};

int main(void)
{
    int n = 0;
    struct Student students[MAX_STUDENTS];

    /* TODO 1：读入 n。 */

    /* TODO 2：循环读入每个学生的成绩和姓名。
     * 注意：题目每行先给成绩，再给姓名。 */

    /* TODO 3：找出最高分的学生。 */

    /* TODO 4：只输出最高分学生的姓名，并换行。 */

    return 0;
}
