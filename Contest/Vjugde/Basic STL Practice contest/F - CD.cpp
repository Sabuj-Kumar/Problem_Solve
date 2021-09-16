#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    while(scanf("%d %d",&n,&m) && n != 0 && m != 0)
    {
        vector<long long> v1(n);
        vector<long long> v2(m);

        int j = 0,count = 0;

        for(int i = 0; i < n; i++)
            cin >> v1[ i ];

        for(int i = 0; i < m; i++)
            cin >> v2[ i ];

        if(n < m)
        {
            for(int i = 0; i < n,j < m; i++)
            {
                if(v1[ i ] == v2[ j ])
                {
                    count++;
                    j++;
                }
                else if(v1[ i ] > v2[ j ])
                {
                    i--;
                    j++;
                }
            }
        }
        else
        {
            for(int i = 0; i < m,j < n; i++)
            {
                if(v2[ i ] == v1[ j ])
                {
                    count++;
                    j++;
                }
                else if(v2[ i ] > v1[ j ])
                {
                    i--;
                    j++;
                }
            }
        }
        cout << count << endl;

        v1.clear();
        v2.clear();
    }
    return 0;
}
