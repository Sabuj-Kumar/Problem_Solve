#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long  n,count = 0,d,i;

    cin >> n >> d;

    long long a[ n ];

    for(i = 0; i < n; i++)
        cin >> a[ i ];

    for(i = 0; i < n; i++)
    {
        if(i == 0)
        {
            count++;

            if( (a[ i ] + d) < (a[ i + 1] - d) )
                count++;
        }
        else
        {
            if( (a[ i ] - d) >= (a[ i-1 ] + d) )
                count++;

            if( (a[ i ] + d) < (a[ i + 1] - d))
                count++;
        }
    }

    cout << count << endl;

    return 0;
}
