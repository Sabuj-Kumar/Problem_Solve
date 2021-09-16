#include<bits/stdc++.h>
#include<math.h>
#define n 1000100

bool a[ n ];

using namespace std;

map<int,int> mp;
map<int,int> :: iterator it;

void seive()
{
    int i,j,root = sqrt(n);

    a[ 0 ] = 1;
    a[ 1 ] = 1;

    for(i = 2; i <= root; i++)
       if(a[ i ] == 0)
          for(j = i*i; j <= n; j += i)
            a[ j ] = 1;
}
int main()
{
    seive();

    long long test;

    cin >> test;

    while(test--)
    {
        long long low,high,i,j;
        long long count_ = 0,max_ = 0,max_out = 0;

        cin >> low;
        cin >> high;

        for(i = low; i <= high; i++)
        {
            if(a[ i ] == 0)
            {
                low = i;
                break;
            }
        }
        for(i = (low + 1); i <= high; i++)
        {
            if(a[ i ] == 0)
            {
                mp[ i - low ]++;

                if(max_ < mp[ i - low ])
                {
                    if(max_ <  mp[ i - low ])
                    {
                         max_ = mp[ i - low ];

                         max_out = i - low;
                    }
                }
                low = i;
            }
        }

        for(it = mp.begin(); it != mp.end(); it++)
        {
            if(max_ == it -> second)
            {
                count_++;

                if(count_ > 1)
                    break;
            }
        }
        if(count_ == 1)
           cout << "The jumping champion is " << max_out << endl;

        else
            cout << "No jumping champion\n";

        mp.clear();
    }
    return 0;
}
