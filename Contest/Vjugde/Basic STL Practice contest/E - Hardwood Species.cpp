#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long test;

    scanf("%lld",&test);

    getchar();
    getchar();

    while(test--)
    {
        map<string,double> mp;
        map<string,double> :: iterator it;
        long long count = 0;
        double avg = 0;
        string s;

        while(getline(cin,s) && s.size() > 0)
        {
            mp[s]++;
            count++;
        }

        avg = 100.0 / count;

        for(it = mp.begin(); it != mp.end(); it++)
        {
            it->second *= avg;
            cout << it->first;
            printf(" %.4lf\n",(*it).second);
        }
        if(test > 0)
            cout << endl;

        mp.clear();
    }
    return 0;
}
