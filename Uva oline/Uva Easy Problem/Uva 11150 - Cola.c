#include<stdio.h>
int main()
{
    int cola,n;
    while(scanf("%d",&cola)==1)
    {
        ///scanf("%d",&cola);
        n = cola;
        while( n > 2 )
         {
            cola += ( n / 3);
            n = ( n / 3 ) + ( n % 3 );
         }
         if( n == 2 )
         printf("%d\n",cola+1);
         else
         printf("%d\n",cola);
    }
   return 0;
}
