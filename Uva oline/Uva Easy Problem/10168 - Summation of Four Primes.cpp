#include<bits/stdc++.h>
#define N 10000010

using namespace std;

bool a[ N ];

void sieve()
{
    long long i,j,root = sqrt(N);

    for(i = 2; i <= root; i++)
       if(a[ i ] == 0)
         for(j = i*i; j < N; j += i)
            a[ j ] = 1;
}
int main()
{

    return 0;
}
