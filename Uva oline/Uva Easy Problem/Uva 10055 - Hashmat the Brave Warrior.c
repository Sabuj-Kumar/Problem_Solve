#include<stdio.h>
int main()
{
    long long  a,b,sum=0;

    for(;scanf("%lld%lld",&a,&b)!=EOF;)
    {
        if(a>=b)
        {
            sum=a-b;
        }
        else
        {
            sum=b-a;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

