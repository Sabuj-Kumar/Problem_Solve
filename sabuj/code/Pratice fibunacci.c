#include<stdio.h>
int main()
{
    int n,a=0,b=1,sum=0,i;
    scanf("%d",&n);
    for( i = 0; i < n; i++ )
    {
        printf("%d ",a);
        sum = a + b;
        a = b;
        b = sum;
    }

}
