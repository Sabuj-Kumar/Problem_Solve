#include<stdio.h>
int main()
{
    double a,b,sum=0;
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a,&b);
        a=((9*a)+32)/5;
        sum=a+b;
        sum=((5*sum)-32)/9;
        printf("Case %d: %.2lf\n",i,sum);
    }
  return 0;
}
