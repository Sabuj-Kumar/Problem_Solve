#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define n 1000100

using namespace std;

long long a[ n ];

void seive()
{
    long long i,j,root = sqrt(n);

    a[ 0 ] = 1;
    a[ 1 ] = 1;

    for(i = 4; i <= n; i += 2)
      a[ i ] = 1;

    for(i = 3; i <= root; i += 2)
       if(a[ i ] == 0)
         for(j = i*i; j <= n; j += i)
            a[ j ] = 1;
}
int main()
{
    seive();

    long long input,i;

    while(scanf("%lld",&input) && input)
    {
        long long count = 0;

        for(i = 2; i <= input/2; i++ )
        {
            if(a[ input ] == 0)
            {
                count++;
                break;
            }
            if(a[ i ] == 0)
                if(input % i == 0)
                    count++;
        }
        printf("%lld : %lld\n",input,count);
    }

    return 0;
}
