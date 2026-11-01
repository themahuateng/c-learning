# include <stdio.h>
void prinfg( int a[])
{
     for (int i = 0;i < 7;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
int main (void)
{
    int a[] = {5,3,8,1,2,6,5};
    prinfg(a);
    int b;
    for (int i = 0 ; i<6;i++)
    {
        for (int j = 0 ; j<6-i;j++)
        {

            if(a[j]>a[j+1])
            {
            b = a[j+1];
            a[j+1] = a[j];
            a[j] = b;
            }
        }
    }
    prinfg(a);
    return 0;
}