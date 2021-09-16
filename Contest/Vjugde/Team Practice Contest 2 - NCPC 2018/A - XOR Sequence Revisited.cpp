#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        long long l,r,output;

        cin >> l >> r;

        output = (l|r)^(l^r);

        cout << output << endl;
    }
    return 0;
}
