#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        int n,max_ = -1,min_ = 101;

        cin >> n;

        int a[ n ];

        for(int i = 0; i < n; i++)
        {
            cin >> a[ i ];

            if(a[ i ] > max_)
                max_ = a[ i ];

            if(a[ i ] < min_)
                min_ = a[ i ];
        }

        cout << (max_ - min_) + (max_ - min_) << endl;
    }
    return 0;
}
