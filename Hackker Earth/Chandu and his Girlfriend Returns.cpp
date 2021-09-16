#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void marge(long long a[],long long start,long long mid,long long end,long long n)
{
    long long i = start,j = mid + 1,index = start;

    long long temp[ n ];

    while(i <= mid && j <= end )
    {
        if(a[ i ] < a[ j ])
        {
            temp[ index ] = a[ j ];
            j++;
        }
        else
        {
            temp[ index ] = a[ i ];
            i++;
        }
        index++;
    }
    while(i <= mid)
    {
        temp[ index ] = a[ i ];
        i++;
        index++;
    }
    while(j <= end)
    {
        temp[ index ] = a[ j ];
        index++;
        j++;
    }
    for(i = start; i <= end; i++)
        a[ i ] = temp[ i ];
}
void marge_sort(long long a[],long long start,long long end,long long n)
{
    long long mid = (start + end) / 2;

    if( start >= end)
        return;

    marge_sort(a,start,mid,n);
    marge_sort(a,mid+1,end,n);
    marge(a,start,mid,end,n);
}

int main()
{
    int test;

    //freopen("input.txt","r",stdin);

    scanf("%d",&test);

    while(test--)
    {
        long long n,m,input;

        scanf("%lld %lld",&n,&m);

        long long a[ n+m ],i;

        memset(a,0,sizeof(a));

        for(i = 0; i < n; i++)
            scanf("%lld",&a[ i ]);

        for(i = n; i < n+m; i++)
            scanf("%lld",&a[ i ]);

        marge_sort(a,0,(n+m-1),(n + m));

        for(i = 0; i < n+m; i++)
            printf("%lld ",a[ i ]);

    }
    return 0;
}
