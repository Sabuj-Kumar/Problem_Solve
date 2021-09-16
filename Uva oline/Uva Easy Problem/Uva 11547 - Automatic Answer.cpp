#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test;

    sf("%d",&test);

    while(test--)
    {
        int input = 0,result = 0,t = 0,mod = 0;

        sf("%d",&input);

        result = (((((input * 567) / 9) + 7492) * 235) / 47) - 498;

        while(t < 2)
        {
            mod = result % 10;

            result /= 10;

            t++;
        }
        if( mod < 0 )
          mod *= -1;

        printf("%d\n",mod);
    }
    return 0;
}
