#include<bits/stdc++.h>

using namespace std;

long long mod;

void Convertion(long long input)
{
    if(input == 0)
        return;

    Convertion(input/2);

    cout <<input%2;
}
int main()
{
    long long test;

    cin >> test;

    while(test--)
    {
        long long input;

        cin >> input;

        Convertion(input);

        cout << "\n";
    }
    return 0;
}
