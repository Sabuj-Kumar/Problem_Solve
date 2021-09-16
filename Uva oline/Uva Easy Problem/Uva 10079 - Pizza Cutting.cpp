#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long long N;

    while( scanf("%lld",&N) && N >= 0 )
    {
       long long sum = ( N * ( N + 1 ) ) / 2 + 1;

       printf("%lld\n",sum);
    }

    return 0;
}
