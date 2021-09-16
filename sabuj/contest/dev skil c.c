#include<stdio.h>

long long fact( long long  a)
{
    long long i,mul = 1;
    for ( i = 1; i <= a; i++ )
        mul *= i;
    return mul;
}
long long sum( long long a )
{
    long long i,jog=0;
    for( i = 1; i <= a; i++ )
        jog += i;
    return jog;
}
int main()
{
    long long T,i,input;
    scanf("%lld",&T);
    for( i = 1; i <= T; i++ )
    {
       scanf("%lld",&input);
      long long f=1,s=0,j;

      for ( j = 1; j <= input; j++ )
        f *= j;
      for ( j = 1; j <= input; j++ )
        s += j;
       if ( s == f )
        printf("Case %lld-> YES;\n",i);
       else
        printf("Case %lld-> NO;\n",i);
    }
    return 0;
}
