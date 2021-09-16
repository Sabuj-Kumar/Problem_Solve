#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ///freopen("input.txt","r",stdin);
    long long test;
    scanf("%lld",&test);
    getchar();
    getchar();

    while(test--)
    {
        map<string,double> mp;
        map<string,double>::iterator it;

        string s;

        double avg = 0;
        long long count = 0;

        while(getline(cin,s) && s.length() != 0)
        {
            mp[s] = ++mp[s];
            count++;
        }
        avg = (100.0 / count);

        for(it = mp.begin(); it != mp.end(); it++)
        {
            it->second *= avg;
            cout<<it->first<<" ";
            printf("%.4lf\n",(*it).second);
        }
        if(test != 0)
          printf("\n");

        mp.clear();
    }
    return 0;
}
