#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    for(int t = 1; t <= test; t++)
    {
        long long base,divisible,count_ = 0;

        cin >> base;
        cin >> divisible;

        if(base % divisible == 0)
            cout << "Case " << t << ": " << base/divisible-1 << endl;

        else
            cout << "Case " << t << ": " << base/divisible << endl;
    }
    return 0;
}
