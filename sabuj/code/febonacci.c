#include<stdio.h>
int main()
{
    int i,n,a=0,b=1,sum=0;
    printf("Enter The Limiting value : ");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        printf("%d ",a);
        sum=a+b;
        a=b;
        b=sum;
    }
    return 0;

}
