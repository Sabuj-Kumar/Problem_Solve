#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

long long power(long long a,long long b)
{
    long long i,x = 1;

    for(i = 0; i < b; i++)
        x *= a;

    return x;
}
int main()
{
    long long test;

    scanf("%lld",&test);

    while(test--)
    {
        long long a,i = 1,sum = 0;

        while(scanf("%lld",&a) && a != 0)
        {
           sum += 2*power(a,i);
           i++;
        }
        if(sum <= 5000000)
           printf("Price = %lld\n",sum);

        else
           printf("Too expensive\n");
    }
    return 0;
}
