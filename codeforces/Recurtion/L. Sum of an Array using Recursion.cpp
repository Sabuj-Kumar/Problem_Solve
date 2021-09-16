#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

long long sum(long long a[],long long value,long long n,long long sum1)
{
    sum1 += value;

    if(n == -1)
        return sum1;

    sum(a,a[ n ],n-1,sum1);
}
int main()
{
    long long n,result = 0;

    cin >> n;

    long long a[ n ];

    for(int i = 0; i < n; i++)
        cin >> a[ i ];

    result = sum(a,0,n-1,0);

    cout << result << endl;

    return 0;
}
