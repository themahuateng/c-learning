/*
 * 练习 2：判断素数（用函数）
 *
 * 任务：写函数 int is_prime(int n)，判断 n 是不是素数
 * 素数：只能被 1 和它本身整除的数（2,3,5,7,11,13...）
 *
 * 思路：
 *   - 1 不是素数；2 是素数
 *   - for 循环 i 从 2 到 n-1
 *   - 如果 n % i == 0 → 能被整除 → 不是素数，return 0
 *   - 循环结束都没被整除 → 是素数，return 1
 */
#include <stdio.h>

/* ===== 在这里写 is_prime 函数 ===== */
int is_prime(int n) {
    if (n < 2)
    {
        return 0;/* code */
    }
    
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;/* code */
        }
        /* code */
    }
    return 1;
}

int main(void)
{
    printf("is_prime(2)  = %d\n", is_prime(2));
    printf("is_prime(7)  = %d\n", is_prime(7));
    printf("is_prime(9)  = %d\n", is_prime(9));
    printf("is_prime(97) = %d\n", is_prime(97));

    return 0;
}
