#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    char name[20];
    int age;
    struct Date birthday;
};

int main(void)
{
    struct Student s = {"Tom", 18, {2007, 5, 12}};

    printf("name = %s\n", s.name);
    printf("age = %d\n", s.age);

    /* TODO：打印 s 的出生年份 */
    char years[100];
   snprintf(years,sizeof(years), "%s, %d years old, birthday: %d-%02d-%02d",
         s.name,
         s.age,
         s.birthday.year,
         s.birthday.month,
         s.birthday.day);
   printf("%s",years);

    printf("month = %d\n", s.birthday.month);

    

    return 0;
}