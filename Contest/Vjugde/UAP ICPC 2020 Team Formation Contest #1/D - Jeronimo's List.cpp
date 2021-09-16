#include<bits/stdc++.h>

using namespace std;

const int N = 3 * 1e7;

int a[ N + 5 ],ans[ N + 5 ];
int cnt[ N + 5 ] = { 0 };

int main(){

    //freopen("in.txt","r",stdin);

    int n,m,q;

    cin >> n >> m >> q;

    for(int i = 1; i <= m; i++){

        cin >> a[ i ];

        cnt[ a[ i ] ]++;
    }

    for(int i = m + 1; i <= n; i++){

        a[ i ] = (a[ i - m ] + a[ i - m + 1 ]) % N;

        cnt[ a[ i ] ]++;
    }

    int ind = 1;

    for(int i = 0; i < N; i++){

        while(cnt[ i ] > 0){

            ans[ ind++ ] = i;

            cnt[ i ]--;
        }
    }
//    for(int i = 1; i <= n; i++) cout << a[ i ] << " ";
//
//    cout << endl;

    while(q--){

        cin >> ind;

        cout << ans[ ind ] << endl;
    }

    return 0;
}
