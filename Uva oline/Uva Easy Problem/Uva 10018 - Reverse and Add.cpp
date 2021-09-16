#include<stdio.h>
#include<iostream>

#define pf printf
#define sf scanf

long long rev(long long recive)
{
    long long p,sum = 0,l = 1,value = 0;

    value = recive;

    while(value > 0)
    {
        value /= 10;
        l *= 10;
    }

    l /= 10;

    while(recive > 0)
    {
        p = recive % 10;
        recive /= 10;
        sum += p * l;
        l /= 10;
    }
    return sum;
}

int main()
{
    int test;

    sf("%d",&test);

    while(test--)
    {
        long long input = 0,check = 0,sum = 0,count = -1,n = 0;

        sf("%lld",&input);

        n = input;

        while(1)
        {
            check = rev(n);

            count++;

            if(check == n)
               break;

            else
               sum = check + n;

            n = sum;
        }
        pf("%lld %lld\n",count,check);
    }
    return 0;
}
