# include <stdio.h>
int main(void)
{
 int a[3][3] = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
    };
    int b[3][3] =  {0};
    for (int i = 0;i < 3;i ++)
    {
        for(int j =0;j < 3 ; j ++){
        b[j][i] = a[i][j];
        }
    }
    for(int k = 0 ; k < 3 ; k++)
    {
        for (int l = 0 ; l < 3 ; l++)
        {printf("%d",b[k][l]);
        }
        printf("\n");
    }
    return 0;
}