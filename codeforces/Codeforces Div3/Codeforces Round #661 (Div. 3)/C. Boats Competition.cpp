#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    while( t-- ){

        int n;

        cin >> n;

        int a[ n + 5 ];

        for(int i = 1; i <= n; i++) cin >> a[ i ];

        vector< int > vis;
        vis.resize( n + 5 );

        int ans = 0;

        for(int k = 1; k <= n + n; k++){

            for(int i = 1; i <= n; i++) vis[ i ] = 0;

            int cnt = 0;

            for(int i = 1; i <= n; i++){

                for(int j = i + 1; j <= n; j++){

                    if(a[ i ] + a[ j ] == k and vis[ i ] == 0 and vis[ j ] == 0){

                        vis[ i ] = vis[ j ] = 1;
                        cnt++;
                    }
                }
            }
            ans = max(ans,cnt);
        }

        cout << ans << endl;
    }
    return 0;
}
