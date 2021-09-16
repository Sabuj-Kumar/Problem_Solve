#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define n 10000

int a[ n ];
int b[ n ];
long long lucky[ n ];

using namespace std;

void lucky_number(int N)
{
    long long num = 29,j = 1,i;

    while(j <= 1000)
    {
        num++;
        int count = 0;

        for(int i = 0; i < N; i++)
        {
            if(b[ i ] <= ( num / 2 ))
            {
                if(num % b[ i ] == 0)
                    count++;

                if(count == 3)
                {
                    lucky[ j ] = num;
                    j++;
                    break;
                }
            }
            else
                break;
        }
    }
}

void seive()
{
    a[ 0 ] = 1;
    a[ 1 ] = 1;

    int i,j,root = sqrt(n);

    for(i = 4; i <= n; i += 2)
        a[ i ] = 1;

    for(i = 3; i <= root; i += 2)
        if(a[ i ] == 0)
          for(j = i * i; j <= n; j += i)
            a[ j ] = 1;

    j = 0;

    for(i = 2; i < n; i++)
    {
        if(a[ i ] == 0)
        {
            b[ j ] = i;
            j++;
        }
    }
    lucky_number(j);
}
int main()
{
    seive();

    int test;

    scanf("%d",&test);

    while(test--)
    {
        int N;

        scanf("%d",&N);

        printf("%lld\n",lucky[ N ]);
    }
    return 0;
}
