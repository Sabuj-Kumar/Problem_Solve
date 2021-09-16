#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int input,i;
    map<int,int> mp;
    vector<int> v;

    while(scanf("%d",&input) == 1)
    {
        if(mp[input] == 0)
        {
            mp[input] = 1;
            v.push_back(input);
        }
        else
            mp[input]++;
    }
    for(i = 0; i < v.size(); i++)
        cout << v[ i ] << " " << mp[v[i]] << endl;

    return 0;
}
