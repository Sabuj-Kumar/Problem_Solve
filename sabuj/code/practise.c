#include<stdio.h>
int main()
{
    int n,x,i,sum=0,mul=1,fact=1;
    scanf("%d %d",&x,&n);
    for( i = 1; i <= n; i++ )
    {
      mul *= x;
      fact *= i;
    }
    printf("%d\n%d\n",mul,fact);
    return 0;
}
