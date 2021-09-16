#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int power( int a,int b )
{
    int i,pow = 1;

    for( i = 0; i < b; i++ )
       pow *= a;

    return pow;
}
int main()
{
    char output[100],input[100];

    int a,b,c;

    while( scanf("%s %d %d",input,&a,&b) == 3 )
    {
        int i = 0,j = 0,p = 0,k = 0,convert = 0,mod = 0;

        for( i = 0; input[ i ] != '\0'; i++ );

        for( int j = --i; j >= 0; j-- )
        {
            if( input[ j ] >= 'A' && input[ j ] <= 'F' )
               c = input[ j ] - 55;

            else
               c = input[ j ] - 48;

            convert += c * power( a,p );

            p++;
        }
        if( convert == 0 )
          printf("      0\n");

        else
        {
            while( convert > 0 )
            {
                mod = convert % b;

                convert /= b;

                if( mod > 9 )
                {
                    if( mod == 10 )
                       output[ k ] = 'A';

                    else if( mod == 11 )
                       output[ k ] = 'B';

                    else if( mod == 12 )
                       output[ k ] = 'C';

                    else if( mod == 13 )
                       output[ k ] = 'D';

                    else if( mod == 14 )
                       output[ k ] = 'E';

                    else
                       output[ k ] = 'F';
                }
                else
                  output[ k ] = mod + 48;

                 k++;
             }

             if( k < 7 )
             {
                while( k < 7 )
                {
                   output[ k ] = ' ';
                   k++;
                }
                output[ k ] = '\0';
             }
             else
                output[ k ] = '\0';

             if( k > 7 )
               printf("  ERROR\n");

             else
             {
                 for( j = --k ; j >= 0; j-- )
                    printf("%c",output[ j ]);

                 printf("\n");
             }
        }
    }
    return 0;
}
