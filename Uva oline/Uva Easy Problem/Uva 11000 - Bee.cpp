#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

long long fib(long long m)
{
    long long a,b,sum1 = 0,store1 = 0,i;

    a = 1;
    b = 1;

    for( i = 1; i <= m; i++ )
    {
        sum1 += a;

        store1 = a+b;

        a = b;

        b = store1;
    }
    return sum1;
}

int main()
{
    while(1)
    {
        long long sum1 = 0,sum2 = 0,store1 = 0,total = 0,n;

        scanf("%lld",&n);

        if( n == -1)
           break;

        sum1 = fib(n);

        sum2 = fib(n-1)+1;

        total = sum1 + sum2;

        pf("%lld %lld\n",sum1,total);
    }
    return 0;
}
