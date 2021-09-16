#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int input;

    while( scanf("%d",&input) == 1 )
    {
        long long sum = 0,i;

        for( i = 1; i <= input; i++ )
          sum += i*i*i;

        printf("%lld\n",sum);
    }
    return 0;
}
