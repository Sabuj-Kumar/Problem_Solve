#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    long long a,b;

    while( sf("%lld %lld",&a,&b) )
    {
        int mod1 = 0,mod2 = 0,sum = 0,flage = 0,carry = 0;

        if(a == 0 && b == 0)
            break;

        while(a || b)
        {
            mod1 = a % 10;
            mod2 = b % 10;

            a /= 10;
            b /= 10;

            sum = (mod1 + mod2 + flage);

            if( sum >= 10 )
            {
                flage = 1;
                carry++;
            }
            else
                flage = 0;
        }
        if(carry == 0)
          pf("No carry operation.\n");

        else if(carry == 1)
          pf("%d carry operation.\n",carry);

        else
          pf("%d carry operations.\n",carry);
    }
    return 0;
}
