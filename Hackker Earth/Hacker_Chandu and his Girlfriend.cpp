#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Marge(long long a[],int start,int mid,int end,int n)
{
    int i = start,j = (mid + 1),index = start,k;
    int temp[n];

    while(i <= mid && j <= end)
    {
        if(a[ i ] >= a[ j ])
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
    {
        a[ i ] = temp[ i ];
    }
}
void Marge_Sort(long long a[],int start,int end,int n)
{
    if(start >= end)
        return;

    int mid = (start + end) / 2;

    Marge_Sort(a,start,mid,n);
    Marge_Sort(a,mid+1,end,n);
    Marge(a,start,mid,end,n);
}
int main()
{
    int test;
    scanf("%d",&test);

    while(test--)
    {
        int n;

        scanf("%d",&n);

        long long input[n] = {0},i;

        for(i = 0; i < n; i++)
            scanf("%lld",&input[i]);

        Marge_Sort(input,0,(n-1),n);

        for(i = 0; i < n; i++)
            printf("%lld ",input[i]);

        printf("\n");
    }
    return 0;
}
