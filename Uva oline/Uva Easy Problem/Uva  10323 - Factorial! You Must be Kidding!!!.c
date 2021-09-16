#include<stdio.h>
long long fact ( long long N )
{
    if ( N < 2 )
     return 1;
    else
     return N * fact( N - 1 );
}
int main()
{
  long long  N;

  while ( scanf("%lld",&N) != EOF )
  {
    if ( N < 0 )
    {
        if ( N % 2 == 0 )
          printf("Underflow!\n");
        else
          printf("Overflow!\n");
    }
    else if( N >= 8 && N <= 13 )
       printf("%lld\n",fact( N ));
    else
    {
        if ( N < 8 )
            printf("Underflow!\n");
        else
            printf("Overflow!\n");
    }
  }
  return 0;
}

