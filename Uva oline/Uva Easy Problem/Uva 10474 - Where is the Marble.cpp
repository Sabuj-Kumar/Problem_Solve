#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void marge(long long a[],long long start,long long mid,long long end,long long n)
{
    long long i = start,j = mid+1,index = start;
    long long temp[ n ];

    while(i <= mid && j <= end)
    {
        if(a[ i ] <= a[ j ])
        {
            temp[ index ] = a[ i ];
            i++;
        }
        else
        {
            temp[ index ] = a[ j ];
            j++;
        }
        index++;
    }
    while(i <= mid)
    {
        temp[ index ] = a[ i ];
        index++;
        i++;
    }
    while(j <= end)
    {
        temp[ index ] = a[ j ];
        index++;
        j++;
    }
    for(i = start; i <= end; i++)
        a[ i ] = temp[ i];
}
void marge_sort(long long a[],long long start,long long end,long long n)
{
    long long mid = (start + end) / 2;

    if(start >= end)
      return;

    marge_sort(a,start,mid,n);
    marge_sort(a,mid+1,end,n);
    marge(a,start,mid,end,n);
}
int main()
{
    long long number_of_marble,query,test = 0;

    while(scanf("%lld %lld",&number_of_marble,&query) && number_of_marble != 0 && query != 0)
    {
        long long marble[ number_of_marble ];
        long long marble_query[ query ];
        long long i,j;

        memset(marble,0,sizeof(marble));
        memset(marble_query,0,sizeof(marble_query));

        for(i = 0; i < number_of_marble; i++)
            scanf("%lld",&marble[ i ]);

        for(i = 0; i < query; i++)
            scanf("%lld",&marble_query[ i ]);

        marge_sort(marble,0,(number_of_marble-1),number_of_marble);

        printf("CASE# %lld:\n",++test);

        for(long long i = 0; i < query; i++)
        {
            bool flage = false;
            long long position = 0;

            for(long long j = 0; j < number_of_marble; j++)
            {
                if(marble_query[ i ] == marble[ j ])
                {
                    flage = true;
                    position = j+1;

                    break;
                }
            }
            if(flage == true)
                printf("%lld found at %lld\n",marble_query[ i ],position);
            else
                printf("%lld not found\n",marble_query[ i ]);
        }
    }
    return 0;
}
