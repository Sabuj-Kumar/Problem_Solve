#include<stdio.h>
#include<iostream>
#define limit 3001

using namespace std;

int main()
{
    int n = 0;

    while( scanf("%d",&n) == 1 )
    {
        int i = 0,j = 0,value = 0,k = 0,flag = 0,check = 0;

        int a[ limit ] = {0},b[ limit ] = {0};

        for( i = 0; i < n; i++ )
           scanf("%d",&a[ i ]);

        if( n > 1 )
        {
            for( i = 0; i < n - 1; i++ )
            {
                b[ j ] = a[ i+1 ] - a[ i ];

                if( b[ j ] < 0 )
                   b[ j ] *= -1;

                j++;
            }
            for( i = 1; i < j; i++ )
            {
                value = b[ i ];

                k = i - 1;

                while( k >= 0 && b[ k ] < value )
                {
                    b[ k + 1 ] = b[ k];

                    k--;
                }

                b[ k + 1 ] = value;
            }

            for( int i = 0; i <  j; i++ )
            {
               check = b[ i+1 ] - b[ i ];

               if( check < 0 )
                check *= -1;

               if( check == 1 )
               {
                   flag = 1;
               }
               else
               {
                   flag = 0;
                   break;
               }
            }

            if( flag == 1 )
               printf("Jolly\n");

            else
                printf("Not jolly\n");
        }
        else
        {
            if( a[ 0 ] == 1 )
              printf("Jolly\n");

            else
              printf("Not jolly\n");
        }
    }

    return 0;
}
