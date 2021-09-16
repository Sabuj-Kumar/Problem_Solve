#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        string s;
        int count_ = 0;

        cin >> s;

        if(s.length() >= 5)
            cout << 3 << endl;

        else
        {
            if(s[0] == 'o') count_ ++;
            if(s[1] == 'n') count_ ++;
            if(s[2] == 'e') count_ ++;

            if(count_ >= 2)
                cout << 1 << endl;

            else
                cout << 2 << endl;
        }
    }
    return 0;
}
