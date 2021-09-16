#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int a,b,t;

    scanf("%d",&t);

    while( t-- )
    {
        int gcd = 0,lcm = 0;

        scanf("%d %d",&a,&b);

        if( ( b % a ) == 0 )
          printf("%d %d\n",a,b);

        else
          printf("-1\n");
    }
    return 0;
}
