#include<stdio.h>
int sum(int n)
{
  int mod = 0,sum1 = 0;
  while( 1 )
  {
       while (n > 0)
       {
           mod = n % 10;
           sum1 += mod;
           n /= 10;
       }
       if(sum1 > 9)
       {
           n = sum1;
           sum1 = 0;
       }
       else
       break;
  }
   return sum1;
}
int main()
{
    int n;
    while( scanf("%d",&n) && n != 0 )
    printf( "%d\n", sum(n) );
}
