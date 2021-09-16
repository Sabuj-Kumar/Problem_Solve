#include<stdio.h>
#include<iostream>

using namespace std;

int GCD( int a,int b )
{
    if( b == 0 ) return a;

    else return GCD( b,a%b);
}

int main()
{
    int input;

    while(scanf("%d",&input) && input != 0)
    {
       int i,j,sum = 0;

       for( i = 1; i < input; i++ )
       for( j = (i + 1); j <= input; j++ )
       sum += GCD(i,j);

       printf("%d\n",sum);
    }
    return 0;
}
