#include<stdio.h>
int power(int base, int p)
{
    int i,sum=1;
    for(i=0;i<p;i++)
    {
        sum=sum*base;
    }
    return sum;
}
int main()
{
    int i,n,sum=0,p=0;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);
    p=n-1;
    int value;
    printf("Enter The binary Number : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        sum=sum+(value*power(2,p));
        p--;
    }
    printf("%d",sum);
}
