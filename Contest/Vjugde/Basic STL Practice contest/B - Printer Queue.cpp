#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

int main()
{
    freopen("input.txt","r",stdin);
    int test;

    scanf("%d",&test);

    while(test--)
    {
        int n,m,i;

        scanf("%d %d",&n,&m);

        for(i = 0; i < n; i++)
            cin >> vec[ i ];

        for(i = 0; i < n; i++)
            cout << vec[ i ] << " ";

        vec.clear();
    }
    return 0;
}
