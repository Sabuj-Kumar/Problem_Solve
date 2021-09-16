#include<bits/stdc++.h>

using namespace std;

string s;
string b;

int main()
{
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i; j < 3+i; j++)
            b += s[ j ];

        if(b == "ACM")
            break;

        else
            b.clear();
    }
    if(b == "ACM")
        cout << "Fun!\n";

    else
        cout << "boring...\n";

    return 0;
}
