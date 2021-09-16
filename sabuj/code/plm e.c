#include<stdio.h>
int main()
{
    long long m,n,i,size,result=0;
    scanf("%lld",&size);
    for( i = 1; i <= size; i++ )
    {
        scanf("%lld %lld",&m,&n);
        result = (m*n)/2;
        printf("Case %lld: %lld\n",i,result);
    }
}
