#include<stdio.h>
int main()
{
    int  i,c;
    long long sum=0,n,m;
    scanf("%d",&c);
    for(i=1;i<=c;i++)
    {
        scanf("%lld%lld",&n,&m);
        sum=(n*m)/2;
        printf("Case %d: %lld\n",i,sum);
    }
    return 0;
}
