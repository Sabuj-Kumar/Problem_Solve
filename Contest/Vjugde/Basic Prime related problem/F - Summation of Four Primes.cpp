#include<bits/stdc++.h>
#include<math.h>
#define N 10000010

using namespace std;

bool a[ N ];

void seive()
{
    int i,j,root = sqrt(N);

    a[ 0 ] = 1;
    a[ 1 ] = 1;

    for(i = 2; i <= root; i++)
        if(a[ i ] == 0)
            for(j = i * i; j <= N; j += i)
                a[ j ] = 1;
}
int main()
{
    seive();

    long long input;

    while(cin >> input)
    {

    }
    return 0;
}
