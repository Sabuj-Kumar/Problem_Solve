#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a;

    cin >> a;

    int n =  a[ 0 ] - 48;

    if(n % 2 == 0) cout << "EVEN\n";
    else cout << "ODD\n";

    return 0;
}
