#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;

    cin >> n;

    long long a[ n ];

    for(int i = 0; i < n; i++)
    {
        cin >> a[ i ];

        if(a[ i ] % 2 == 0)
            a[ i ] -= 1;
    }
    for(int i = 0; i < n; i++)
    {
         cout << a[ i ];

         if(i < (n-1) )
            cout << " ";
    }

    return 0;
}
