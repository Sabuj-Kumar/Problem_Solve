#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int test;

    for(cin >> test; test--;){

        int n,m,cost = 0;
        cin >> n >> m;
        vector< int > c( n + 5 );
        for(int i = 1; i <= n; i++){

            cin >> c[ i ];

            if(i > 1) cost += c[ i - 1 ] + c[ i ];
        }

        cost += c[ n ] + c[ 1 ];

        if(n <= 2 || m < n) {

            cout << -1 << endl;

            continue;
        }
        cout << cost << endl;

        for(int i = 2; i <= n; i++) cout << i - 1 << " " << i << endl;

        cout << n << " " << 1 << endl;
    }
    return 0;
}
