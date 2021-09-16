#include<stdio.h>
int main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    if( a > b)
    {
        int swap;
        swap = a;
        a = b;
        b = swap;
    }
    int store = 0;
    for( i = 2; i <= a; i++ )
    {
      if( a % i == 0 && b % i == 0 )
      {

          if ( store < i)
            store = i;
      }
    }
    if ( store != 0 )
    printf("GCD Between This Two Number Is = %d\n",store);
    else
    printf("There Is No GCD Between This Two Number's.\n");
    return 0;
}
