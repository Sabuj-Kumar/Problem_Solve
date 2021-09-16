#include<stdio.h>
int main()
{
    long long n,input,i,j,mul=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&input);
        while(1)
        {
            if( input%2==0 )
            {
                mul*=2;
                input/=2;
            }
            else
                break;
        }
        if(mul!=1)
        printf("Case %lld: %lld %lld\n",i,input,mul);
        else
        printf("Case %lld: Impossible\n",i);
        mul=1;
    }
    return 0;
}
