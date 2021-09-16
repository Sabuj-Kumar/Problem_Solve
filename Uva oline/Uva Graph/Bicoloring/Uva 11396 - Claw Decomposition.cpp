#include<bits/stdc++.h>

using namespace std;

vector<int > graph[ 500 ];
int vis[ 500 ];
int bi[ 500 ];
int f;

void BFS(int node){

    int b = 0;

    queue< int > q;

    q.push( node );

    vis[ node ] = 1;

    bi[ node ] = b;

    while(!q.empty()){

        int p = q.front();

        if(bi[ p ] == 0) b = 1;

        else b = 0;

        q.pop();

        for(auto x : graph[ p ]){

            if(!vis[ x ]){

                vis[ x ] = 1;

                q.push( x );

                bi[ x ] = b;
            }
            else if(bi[ x ] == bi[ p ]) f = 1;


    //cout << x << endl;

            if( f ) break;
        }
        if( f ) break;
    }
}
int main(){

    //freopen("input.txt","r",stdin);

    int n;

    while(cin >> n && n){

        int a,b;

        for(int i = 0; i < 500; i++) bi[ i ] = i,vis[ i ] = 0,graph[ i ].clear();

        f = 0;

        while(cin >> a >> b && a && b){

            graph[ a ].push_back( b );
            graph[ b ].push_back( a );
        }

        for(int i = 1; i <= n; i++)
            if(!vis[ i ]) BFS( i );

        if( f ) cout << "NO\n";

        else cout << "YES\n";
    }

    return 0;
}
