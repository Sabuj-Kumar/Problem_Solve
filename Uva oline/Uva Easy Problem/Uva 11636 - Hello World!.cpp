#include<stdio.h>
#include<iostream>

using namespace std;

int power(int a, int b)
{
    int mult = 1;

    for( int i = 0; i < b; i++ )
        mult *= a;

    return mult;
}

int main()
{
    int input,t = 1;

    while( scanf("%d",&input) && input >= 0 )
    {
        int i = 0,count = 0,check = 0;

        for( i = 0; i < input; i++ )
        {
           check = power(2,i);

           if( check >= input )
             break;
        }
        printf("Case %d: %d\n",t,i);

        t++;
    }
    return 0;
}
