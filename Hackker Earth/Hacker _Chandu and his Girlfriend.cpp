#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Marge(vector<long long> &a,long long start,long long mid,long long end)
{
    long long i = start,j = mid+1,index = start,k = 0;

    vector<long long> temp;
    temp.resize(a.size());

    while(i <= mid && j <= end)
    {
        if(a[i] > a[j])
        {
            temp[index] = a[i];
            i++;
        }
        else
        {
            temp[index] = a[j];
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
    for(k = start; k <= end; k++)
        a[k] = temp[k];
}
void Marge_Sort(vector<long long> &input,long long start,long long end)
{
    if(start >= end)
        return;

    long long mid;

    mid = (start + end) / 2;

    Marge_Sort(input,start,mid);
    Marge_Sort(input,(mid+1),end);
    Marge(input,start,mid,end);
}

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        vector< long long > input;
        vector< long long >::iterator it;

        long long n,value,i;

        scanf("%lld",&n);

        for(i = 0; i < n; i++)
        {
            scanf("%lld",&value);
            input.push_back(value);
        }

        Marge_Sort(input,0,(n-1));

        for(it = input.begin(); it != input.end(); ++it)
            cout<<*it<<" ";

        printf("\n");
        input.clear();
    }
    return 0;
}
