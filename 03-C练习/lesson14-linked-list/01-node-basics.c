#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

int main(void)
{
    struct Node *a = malloc(sizeof *a);
    struct Node *b = malloc(sizeof *b);

    if (a == NULL || b == NULL)
    {
        printf("内存分配失败\n");
        free(a);
        free(b);
        return 1;
    }

    a->value = 10;
    b->value = 20;

    /* TODO 1：让 a 的 next 指向 b。 */

    /* TODO 2：让 b 成为最后一个节点，next 指向 NULL。 */

    /* TODO 3：通过 a 找到 b，打印两个节点的 value。 */

    /* TODO 4：释放两个节点，并把指针置为 NULL。 */

    return 0;
}
