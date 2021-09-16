#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    long long N;

    while( scanf("%lld",&N) && N != 0 )
    {
       long long a =  sqrt(N);

        if(  ( a * a ) == N )
         printf("yes\n");

        else
         printf("no\n");
    }

    return 0;
}
