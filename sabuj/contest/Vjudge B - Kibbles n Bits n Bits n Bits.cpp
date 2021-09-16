#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

char str[10];

int POW( int a,int b )
{
    int i,p = 1;

    for( i = 0; i < b; i++ )
       p *= a;

    return p;
}

int main()
{
    int i,T;

    scanf("%d",&T);

    getchar();

    while( T-- )
    {
        int j = 0,k = 0,sum1 = 0,sum2 = 0,sum = 0,mod = 0,store = 0,n,a[14] = {0},b[14] = {0};

        gets(str);

        for( i = 0; str[ i ] != '\0'; i++ )
        {
            if( str[ i ] == '+' || str[ i ] == '-' )
            {
                store = i;

                break;
            }
        }

        for( i = 0; str[ i ] != '\0'; i++ )
        {
            if( i < ( store - 1 ) )
            {
                if( str[ i ] >= 'A' && str[ i ] <= 'F' )
                {
                    n = str[ i ] - 55;

                    while( n > 0 )
                    {
                        mod = n % 2;

                        a[ j ] = mod;

                        n /= 2;

                        j++;
                    }
                }
                else
                {
                   n = str[ i ] - 48;

                   while( n > 0 )
                   {
                       mod = n % 2;

                       a[ j ] = mod;

                       n /= 2;

                       j++;
                   }
                }
            }
            else if ( i > ( store + 1 ) )
            {
                if( str[ i ] >= 'A' && str[ i ] <= 'F' )
                {
                    n = str[ i ] - 55;

                    while( n > 0 )
                    {
                        mod = n % 2;

                        b[ k ] = mod;

                        n /= 2;

                        k++;
                    }
                }
                else
                {
                   n = str[ i ] - 48;

                   while( n > 0 )
                   {
                       mod = n % 2;

                       b[ k ] = mod;

                       n /= 2;

                       k++;
                   }
                }
            }
        }

        j = 0;

        for( i = 0; i < 13; i++ )
        {
           sum1 += a[ i ] * POW(2,j);

           j++;
        }

        j = 0;

        for( i = 0; i < 13; i++ )
        {
           sum2 += b[ i ] * POW(2,j);

           j++;
        }

        if( str [ store ] == '+')
        {
             for( i = 12; i >= 0; i-- )
               printf("%d",a[i]);

               printf(" + ");

             for( i = 12; i >= 0; i-- )
               printf("%d",b[i]);

            sum = sum1 + sum2;
        }
        else
        {
            if( sum1 >= sum2 )
            {
                for( i = 12; i >= 0; i-- )
                   printf("%d",a[i]);

                   printf(" - ");

                for( i = 12; i >= 0; i-- )
                   printf("%d",b[i]);

                sum = sum1 - sum2;
            }
            else
            {
                for( i = 12; i >= 0; i-- )
                   printf("%d",b[i]);

                   printf(" - ");

                for( i = 12; i >= 0; i-- )
                   printf("%d",a[i]);

                sum = sum2 - sum1;
            }
        }

        printf(" = %d\n",sum);

    }

    return 0;
}
