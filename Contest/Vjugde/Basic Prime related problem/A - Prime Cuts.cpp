#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define n 1100

int a[ n ],b[ n/2 ];

using namespace std;

void seive()
{
    int i,j,root = sqrt(n);

    for(int i = 4; i < n; i += 2)
        a[ i ] = 1;

    for(i = 3; i < root; i += 2)
        if(a[ i ] == 0)
          for(j = i * i; j < n; j += i)
            a[ j ] = 1;

    j = 0;

    for(i = 1; i < n; i++)
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

    int input,c,store;

    while(scanf("%d %d",&input,&c) == 2)
    {
        int len = 0,i;

        printf("%d %d:",input,c);

        for(len = 0; b[ len ] <= input; len++);

        if(len % 2 == 0)
            store = (2 * c);

        else
            store = (2 * c) - 1;

        if(store < len)
        {
            if(len % 2 == 0)
              for(i = (len / 2) - (store / 2); i < (len / 2) + (store / 2); i++)
                printf(" %d",b[ i ]);

            else
              for(i = (len / 2) - (store / 2); i <= (len / 2) + (store / 2); i++)
                printf(" %d",b[ i ]);

            printf("\n\n");
        }
        else
        {
            for(i = 0; b[ i ] <= input; i++)
               printf(" %d",b[ i ]);

             printf("\n\n");
        }
    }
    return 0;
}

