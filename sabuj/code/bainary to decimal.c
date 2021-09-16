#include<stdio.h>
int power(int base,int p)
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
    int sum=0,i,n,pw;

    printf("Enter The Value Of N : ");
    scanf("%d",&n);

    pw=n-1;
    int value;

    printf("Enter The Binary Number : ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&value);

        sum=sum+(value*power(2,pw));
        pw--;
    }
    printf("%d",sum);
}
