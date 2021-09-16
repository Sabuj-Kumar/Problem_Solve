#include<bits/stdc++.h>

using namespace std;

map<long long,int> mp;
map<long long,int> :: iterator it;

int main()
{
    int n,count_ = 0;

    cin >> n;

    long long a[ n ];

    for(int i = 0; i < n; i++)
    {
        cin >> a[ i ];
        mp[a[ i ] ]++;
    }

    for(it = mp.begin(); it != mp.end(); it++)
        if(it -> second > 1)
            count_ += --it->second;

    cout << count_ << endl;

    mp.clear();

    return 0;
}
