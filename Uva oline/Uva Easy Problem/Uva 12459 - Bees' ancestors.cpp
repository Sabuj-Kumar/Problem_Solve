#include<bits/stdc++.h>

using namespace std;

int main(){

    unsigned long long n,a[ 82 ] = {0};

    a[ 0 ] = 1;
    a[ 1 ] = 1;

    for(int i = 2; i < 82; i++) a[ i ] = a[ i - 1 ] + a[ i - 2 ];

    while(cin >> n && n) cout << a[ n ] << "\n";

    return 0;
}
