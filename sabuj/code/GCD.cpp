#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int GCD(int a,int b)
{
    if( b == 0)
      return a;

    else
      return GCD(b,a%b);
}

int main()
{
   int x,y,gcd,lcm;

   sf("%d %d",&x,&y);

   gcd = GCD(x,y);

   lcm = (x * y) / gcd;

   pf("GCD IS = %d\n\nLCM IS = %d\n",gcd,lcm);

   return 0;
}
