#include<bits/stdc++.h>

using namespace std;

vector< int >graph[ 110 ];
stack<int> stak;
bool vis[ 110 ];
int u;

void dfs(int n){

    if(vis[ n ]) return;

    vis[ n ] = true;

    for(auto x : graph[ n ]) dfs( x );

    stak.push( n );
}
int main(){

    int n,m;

    memset(vis,false,sizeof vis);

    while(cin >> n >> m && n && m){

        int x,a,b,f = 1;

        u = 0;

        while(m--){

            cin >> a >> b;

            if(f){

               x = a;

               f = 0;
            }

            graph[ a ].push_back( b );
        }

        for(int i = 1; i <= n; i++){

            if(!vis[ i ]) dfs( i );
        }

        while(!stak.empty()){

            cout << stak.top() << " ";

            stak.pop ();
        }
    }

    return 0;
}
