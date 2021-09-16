#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int t;

    cin >> t;

    for(int cs = 1; cs <= t; cs++){

        ll a,b,n;

        cin >> a >> b >> n;

        ll x = ((a+n) ) / 2;
        ll y = ((b+n) ) / 2;

        cout << "Case "  << cs << ": "<< __gcd(y,x) + 1 << endl;
    }
    return 0;
}
