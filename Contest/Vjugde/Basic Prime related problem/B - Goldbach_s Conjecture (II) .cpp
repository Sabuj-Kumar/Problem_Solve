#include<stdio.h>
#include<bits/stdc++.h>
#define n 33000
#include<math.h>

using namespace std;

int a[ n ];
int b[ n/2 ];
map<int,int> mp;

void seive()
{
    int i,j,root = sqrt(n);

    a[ 0 ] = 1;
    a[ 1 ] = 1;

    for(i = 4; i <= n; i += 2)
        a[ i ] = 1;

    for(i = 3; i <= root; i += 2)
        if(a[ i ] == 0)
          for(j = i*i; j <= n; j += i)
            a[ j ] = 1;

    j = 0;

    for(i = 2; i <= n; i++)
    {
        if(a[ i ] == 0)
        {
            b[ j ] = i;
            j++;
        }
    }
}
int main()
{
    seive();

    int input,i,j;

    while(scanf("%d",&input) && input != 0)
    {
        for(i = 0; b[ i ] < input; i++)
        {
            for(j = i; b[ j ] < input; j++)
            {
                if(b[ i ] + b[ j ] == input)
                    mp[ input ]++;
            }
        }
        printf("%d\n",mp[ input ]);
        mp.clear();
    }

    return 0;
}
