#include<bits/stdc++.h>

using namespace std;

int main()
{
    string input,input1;

    cin >> input;

    input1 = input;

    reverse(input.begin(),input.end());

    if(input1 == input) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
