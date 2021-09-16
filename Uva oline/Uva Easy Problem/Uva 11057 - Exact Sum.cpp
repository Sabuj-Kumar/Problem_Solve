#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long input;

    while(scanf("%lld",&input) == 1 )
    {
       long long a[input] = {0},price = 0,sub = 0,min = 1000001,m = 0,p,q;

       for( int i = 0; i < input; i++ )
          scanf("%lld",&a[ i ]);

       scanf("%lld",&price);

       for( int i = 0; i < input; i++ )
       {
           for( int j = i + 1; j < input; j++ )
           {
               if( ( a[ i ] + a[ j ] ) == price )
               {
                   if( a[ i ] > a[ j ] )
                     sub = a[ i ] - a[ j ];

                   else
                     sub = a[ j ] - a[ i ];

                     m = 1;
               }
               if( m == 1 )
               if( min > sub )
               {
                   min = sub;

                   p = a[ i ];

                   q = a[ j ];
               }
           }
       }
       if( p >= q )
          printf("Peter should buy books whose prices are %lld and %lld.\n\n",q,p);

       else
          printf("Peter should buy books whose prices are %lld and %lld.\n\n",p,q);
    }
    return 0;
}
