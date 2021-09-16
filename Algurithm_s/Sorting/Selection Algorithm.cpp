#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Selection_Sort(int a[],int n)
{
    for(int i = n-1; i >= 1; i--)
    {
        int j = 0;

        for(int k = 1; k <= i; k++)
        {
            if(a[ j ] < a[ k ])
                j = k;
        }
        swap(a[ i ],a[ j ]);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);

    int n;

    cin >> n;

    int a[ n ];

    for(int i = 0; i < n; i++)
        cin >> a[ i ];

    Selection_Sort(a,n);

    for(int i = 0; i < n; i++)
        cout << a[ i ] << " ";

    return 0;
}
