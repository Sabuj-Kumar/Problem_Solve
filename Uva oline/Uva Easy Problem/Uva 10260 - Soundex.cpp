#include<bits/stdc++.h>

using namespace std;

map<char,int> mp;

int main()
{
    mp[ 'B' ] = 1;
    mp[ 'F' ] = 1;
    mp[ 'P' ] = 1;
    mp[ 'V' ] = 1;
    mp[ 'C' ] = 2;
    mp[ 'G' ] = 2;
    mp[ 'J' ] = 2;
    mp[ 'K' ] = 2;
    mp[ 'Q' ] = 2;
    mp[ 'S' ] = 2;
    mp[ 'X' ] = 2;
    mp[ 'Z' ] = 2;
    mp[ 'D' ] = 3;
    mp[ 'T' ] = 3;
    mp[ 'L' ] = 4;
    mp[ 'M' ] = 5;
    mp[ 'N' ] = 5;
    mp[ 'R' ] = 6;

    string s;

    while(cin >> s)
    {
        int i = 0,j = 1,k = 0;
        int len = s.length();
        int s1[ len ];

        memset(s1,0,sizeof(s1));

        while(mp[ s[ k ] ] == 0 && k != len)
            k++;

        s1[ 0 ] = mp[ s[ k ] ];

        for(i = k+1; i < s.size(); i++)
        {
            if( mp[ s[ i ] ] != 0 && mp[ s[ i-1 ] ] != mp[ s[ i ] ] )
            {
                s1[ j ] = mp[ s[ i ] ];
                j++;
            }
        }

        if(s1[ 0 ] != 0)
          for(i = 0; i < j; i++)
            cout << s1[ i ];

        cout << endl;
    }

    return 0;
}
