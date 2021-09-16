#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

bool Search(long long x,long long start,long long end,long long A[])
{
    long long mid = (start + end) / 2;

    if(A[ mid ] == x)
        return true;

    if(start >= end)
        return false;

    if(A[ mid ] < x)
        Search(x,mid+1,end,A);

    else
        Search(x,start,mid-1,A);
}
int main()
{
    //freopen("input.txt","r",stdin);

    long long n;

    bool flag;

    cin >> n;

    long long A[n],s,x;

    cin >> s;

    for(int i = 0;i < n; i++)
        cin >> A[i];

    sort(A,A+n);

    while(s--)
    {
        cin >> x;

        flag = Search(x,0,n-1,A);

        if(flag == true)
            cout << "YES\n";

        else
            cout << "NO\n";
    }
    return 0;
}
