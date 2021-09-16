#include<stdio.h>
#include<bits/stdc++.h>
#define n 80

long long a[ n ];
int i = 0;

using namespace std;

void fib()
{
    long long x = 0,y = 1,j = 0,i = 0;

    while(i <= n)
    {
        a[ i++ ] = x;
        j = x + y;
        x = y;
        y = j;
    }
}
int main()
{
    fib();

    for(int i = 0; i < n; i++)
        printf("%lld ",a[ i ]);

    return 0;
}
