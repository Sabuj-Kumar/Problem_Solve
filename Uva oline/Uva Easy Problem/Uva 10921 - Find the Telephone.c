#include<stdio.h>
#include<string.h>
int main()
{
   char a[1000],b[1000];

   while( scanf("%s",a) != EOF )
   {
        int i = 0;

        for( i = 0; a[i] != '\0'; i++ )
        {
            if( a[ i ] == 'A' || a[ i ] == 'B' || a[ i ] == 'C' )
             b[ i ] = 2 + 48;

            else if( a[ i ] == 'D' || a[ i ] == 'E' || a[ i ] == 'F' )
             b[ i ] = 3 + 48;

            else if( a[ i ] == 'G' || a[ i ] == 'H' || a[ i ] == 'I' )
             b[ i ] = 4 + 48;

            else if( a[ i ] == 'J' || a[ i ] == 'K' || a[ i ] == 'L' )
             b[ i ] = 5 + 48;

            else if( a[ i ] == 'M' || a[ i ] == 'N' || a[ i ] == 'O' )
             b[ i ] = 6 + 48;

            else if( a[ i ] == 'P' || a[ i ] == 'Q' || a[ i ] == 'R' || a[ i ] == 'S' )
             b[ i ] = 7 + 48;

            else if( a[ i ] == 'T' || a[ i ] == 'U' || a[ i ] == 'V' )
             b[ i ] = 8 + 48;

            else if( a[ i ] == 'W' || a[ i ] == 'X' || a[ i ] == 'Y' || a[ i ] == 'Z' )
             b[ i ] = 9 + 48;

            else
             b[ i ] = a[ i ];
        }

        b[ i ] = '\0';

        printf("%s\n",b);
   }
   return 0;
}
