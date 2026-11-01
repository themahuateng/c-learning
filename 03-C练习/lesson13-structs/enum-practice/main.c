#include <stdio.h>

enum Color
{
    RED,
    GREEN,
    BLUE
};

int main(void)
{
    enum Color c = GREEN;

    printf("c = %d\n", c);

    if (c == GREEN)
        printf("GREEN\n");
    else
        printf("NOT GREEN\n");

    return 0;
}