#include <stdio.h>

/* 给 int 起一个外号 */
typedef int MyInt;

/* 定义学生结构体，并给它起外号 Student */
typedef struct Student
{
    char name[20];
    int age;
} Student;

int main(void)
{
    MyInt n = 10;

    Student s1 = {"Tom", 18};

    printf("n = %d\n", n);
    printf("name = %s, age = %d\n", s1.name, s1.age);

    return 0;
}