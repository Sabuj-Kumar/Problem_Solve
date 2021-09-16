#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

long long way(long long a,long long b)
{
    long long i,p1 = 1,p2= 1,p3 = 1;

    for(i = 1; i <= a; i++)
      p1 *= i;

    for(i = 1; i <= b; i++)
      p2 *= i;

    for(i = 1; i <= (a-b); i++)
      p3 *= i;

    return (p1 / (p2 * p3));
}
int main()
{
    long long n,m,output = 0;

    while(sf("%lld %lld",&n,&m) && (n != 0 && m != 0) )
    {
        output = way(n,m);

        printf("%lld\n",output);
    }
    return 0;
}

