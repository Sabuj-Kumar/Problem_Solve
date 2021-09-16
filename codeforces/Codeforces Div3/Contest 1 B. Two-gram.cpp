#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
     int n,max = 0;
     string input;
     char a,b;

     cin>>n>>input;
     map<pair<char,char>,int> mp;

     for(int i = 0; i < n; i++)
     {
        mp[make_pair(input[i],input[i+1])]++;

        if(max < mp[make_pair(input[i],input[i+1])])
        {
            max = mp[make_pair(input[i],input[i+1])];
            a = input[i];
            b = input[i+1];
        }
     }
     cout<<a<<b<<endl;

     return 0;
}
