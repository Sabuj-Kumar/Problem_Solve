#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void print(long long a[],long long value,long long n,long long i)
{
    if(i == 0)
    {
        if(value != -1)
        {
            printf("%d ",value);
            i = 1;
        }
    }
    else if(i == 1)
    {
        if(value != -1)
        {
            printf("%d",value);
            i = 2;
        }
    }
    else
        if(value != -1)
            printf(" %d",value);

    if(n < 0)
       return;

    if(n % 2 == 0) print(a,a[ n ],n-2,i);

    else print(a,-1,n-1,i);
}
int main()
{
    long long n,i;

    cin >> n;

    long long a[ n ];

    for(i = 0; i < n; i++)
        cin >> a[ i ];

    print(a,-1,n-1,0);

    return 0;
}
