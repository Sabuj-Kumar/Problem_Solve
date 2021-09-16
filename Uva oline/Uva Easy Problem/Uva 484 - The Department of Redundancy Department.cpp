#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int> mp;
    vector<int> vec;

    int input,i;

    while(scanf("%d",&input) != EOF)
    {
        if(mp[input] == 0)
        {
            mp[input] = 1;
            vec.push_back(input);
        }
        else
            mp[input] = ++mp[input];
    }
    for(i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" "<<mp[vec[i]]<<endl;

    return 0;
}
