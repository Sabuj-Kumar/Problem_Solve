#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

map<string,int> mp;

void word()
{
    string b,a = "abcdefghijklmnopqrstuvwxyz";
    int count = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            int n = 0;

            count++;




            mp[ b ] = count;
        }
    }
}
int main()
{
    word();

    string input;

    while(cin >> input)
    {
        cout << mp[ input ] << endl;
    }

    mp.clear();

    return 0;
}
