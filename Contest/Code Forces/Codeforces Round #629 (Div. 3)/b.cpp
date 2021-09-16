#include<bits/stdc++.h>

using namespace std;

int I() { int n; scanf("%d",&n); return n; }

int main(){

    vector< int > v;
    v.push_back(0);
    for(int i = 1; i < 100005; i++) v.push_back(i);
    int t = I();

    while( t-- ){

        int n = I(),k = I();

        int j;

        if(k == 1) {

            for(int i = 0; i < n-2; i++) cout << 'a';
            cout << "bb" <<endl;
            continue;
        }

        for(int i = 1; v[ i ] < k; i++) {

            k -= v[ i ];
            j = i;
        }

        string s(n,'a');

        s[ n - j - 2 ] = 'b';
        s[ n - k ] = 'b';

        cout << s << endl;
    }
    return 0;
}
