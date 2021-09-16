#include<stdio.h>
int main()
{
    int a,b,i,store=0,swap=0,flag=0;
    scanf("%d %d",&a,&b);
    if ( a > b)
    {
        swap = a;
        a = b;
        b = swap;
    }
    store = a;
    for( i = a; i > 1; i-- )
    {
      if( a % i == 0 && b % i == 0 )
      {
          if ( store > i)
            store = i;
             flag =1;
      }
    }
    if ( flag == 1 )
    printf("LCD Between This Two Number Is = %d\n",store);
    else
    printf("There Is No LCD Between This Two Number's.\n");
    return 0;
}
