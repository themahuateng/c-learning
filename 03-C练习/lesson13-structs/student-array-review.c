#include <stdio.h>
#include <stdlib.h>
typedef struct Student
{
    char name[20];
    int score;
} Student;
void line(Student s[],int n)
{
    for (int i = 1;i < n;i++)
     {
        int j = i-1;
        Student temp = s[i];
        while(j >=0 && s[j].score < temp.score )
        {    
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = temp;

     }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    Student *s = malloc(n*sizeof(Student));
    if (s==NULL)
    {
        printf("内存分配失败");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("输入第%d个学生姓名和成绩: ", i + 1);
        scanf("%19s%d", s[i].name, &s[i].score);
    }

    printf("原始名单：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", s[i].name, s[i].score);
    }
     Student best = s[0];
     for (int i =0;i<n;i++)
     {
        if(s[i].score>best.score)
        {
            best = s[i];
        }
     }
     printf("最高分：%s,%d\n",best.name,best.score);
    line(s,n);
    printf("排名：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", s[i].name, s[i].score);
    }
free(s);
s = NULL;
    return 0;
}
