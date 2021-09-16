#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

long long happy(long long n)
{
    long long sum = 0,mod = 0;

    while(1)
    {
        while(n > 0)
        {
            mod = n % 10;
            n /= 10;
            sum += mod*mod;
        }

        n = sum;

        if(n < 10)
          break;

        else
          sum  = 0;
    }
    return n;
}

int main()
{
    long long test,i;

    while(sf("%lld",&test)==1)
    {
        for(i = 1; i <= test; i++)
        {
            long long n = 0,check = 0;

            sf("%lld",&n);

            check = happy(n);

            if(check == 1)
              pf("Case #%lld: %lld is a Happy number.\n",i,n);

            else
              pf("Case #%lld: %lld is an Unhappy number.\n",i,n);
        }
    }
    return 0;
}
