#include<bits/stdc++.h>

using namespace std;

int sc() { int n; scanf("%d",&n); return n; }

int main(){

    int test;

    test = sc();

    for(int i = 0; i < test; i++){

        int a[ 3 ];

        for(int j = 0; j < 3; j++)  a[ j ] = sc();

        sort(a,a+3,greater<int>());

        if( a[ 0 ] == a[ 1 ] and a[ 1 ]==a[ 2 ] or a[ 0 ] - (a[ 1 ]+a[ 2 ]) <= 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
