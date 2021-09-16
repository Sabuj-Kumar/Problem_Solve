#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int POWER( int a,int b )
{
    int i,pow = 1;

    for( i = 0; i < b; i++ )
       pow *= a;

    return pow;
}

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
         char a[3][10] = {0};

         int ar[14] = {0},cr[14] = {0},hexa = 0;

         int mod = 0,sum1 = 0,sum2 = 0,binary = 0,decimal = 0;

         int len_a = 0,len_c = 0,len_ar = 0,len_cr = 0,dec = 0;

         int i = 0,j = 0,k = 0,m = 0,o = 1;

         for( i = 0; i < 3; i++ )
            scanf("%s",a[ i ]);

         for( i = 0; a[ 0 ][ i ] != '\0'; i++ )
             len_a++;

         for( i = 0; a[ 2 ][ i ] != '\0'; i++ )
             len_c++;

         for( i = len_a - 1;i >= 0; i-- )
         {
             if( a[ 0 ][ i ] >= 'A' && a[ 0 ][ i ] <= 'F' )
                hexa = a[ 0 ][ i ] - 55;

             else
                hexa = a[ 0 ][ i ] - 48;

             sum1 += hexa * POWER(16,j);

             j++;
         }

         j = 0;

         for( i = len_c - 1;i >= 0; i-- )
         {
             if( a[ 2 ][ i ] >= 'A' && a[ 2 ][ i ] <= 'F' )
                hexa = a[ 2 ][ i ] - 55;

             else
                hexa = a[ 2 ][ i ] - 48;

             sum2 += hexa * POWER(16,j);

             j++;
         }

         binary = sum1;

         k = 0;

         while( binary > 0 )
         {
            mod = binary % 2;

            ar[ k ] = mod;

            binary /= 2;

            k++;
         }

         k = 0;

         binary = sum2;

         while( binary > 0 )
         {
            mod = binary % 2;

            cr[ k ] = mod;

            binary /= 2;

            k++;
         }

         if( a[1][0] == '+' )
         {
             for( i = 12; i >= 0; i-- )
                 cout<<ar[i];

             printf(" %c ",a[1][0]);

             for( i = 12; i >= 0; i-- )
                cout<<cr[i];

             printf(" = %d\n",sum1+sum2);
         }
         else
         {
             if( sum1 >= sum2 )
             {
                 for( i = 12; i >= 0; i-- )
                    cout<<ar[i];

                 printf(" %c ",a[1][0]);

                 for( i = 12; i >= 0; i-- )
                    cout<<cr[i];

                 printf(" = %d\n",sum1-sum2);

             }
             else
             {
                 for( i = 12; i >= 0; i-- )
                    cout<<cr[i];

                 printf(" %c ",a[1][0]);

                 for( i = 12; i >= 0; i-- )
                    cout<<ar[i];

                 printf(" = %d\n",sum2-sum1);
             }
         }
    }

   return 0;
}
