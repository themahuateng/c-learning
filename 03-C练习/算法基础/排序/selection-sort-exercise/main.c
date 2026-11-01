# include <stdio.h>
void printf_array(int a[],int n)
{
    for(int i = 0;i <n; i++ )
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main (void)
{
    int a [] = {6,4,5,4,8,2,1,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    printf_array(a,n);
    for (int i = 0; i < 8; i++)
    {
     int k = i;
     for(int j = i+1;j<9;j++)
     {
       if (a[j] > a[k])
        {
            k = j;  
        }
    }
        if ( k != i)
        {
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
        }
     
    }
    printf_array(a,n);
    return 0 ;

}