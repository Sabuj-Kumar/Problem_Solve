#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int sum(int input)
{
   int j = 0,mod = 0,sum1 = 0,sum2 = 0,store = 0;

   while(input > 0)
   {
       mod = input % 10;

       input /= 10;

       if(j % 2 != 0)
       {
           store = 2 * mod;

           while(store > 0)
           {
              mod = store % 10;

              store /= 10;

              sum1 += mod;
           }
           j++;
       }
       else
       {
           sum2 += mod;
           j++;
       }

   }
   return (sum1+sum2);
}
int main()
{
    long long N,input;

    sf("%lld",&N);

    while(N--)
    {
       long long sum1 = 0;

       for(int i = 0; i < 4; i++)
       {
           sf("%lld",&input);

           sum1 += sum(input);
       }
       if((sum1 % 10) == 0)
         pf("Valid\n");

       else
         pf("Invalid\n");
    }
    return 0;
}
