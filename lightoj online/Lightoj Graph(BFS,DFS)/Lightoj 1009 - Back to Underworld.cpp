#include<bits/stdc++.h>
#define mx 20010

using namespace std;

vector<int> graph[ mx ];
map< int,int > mp;
int vis[ mx ];

void BFS(int root){

    queue< int > q;

    q.push( root );

    vis[ root ] = 0;

    while(!q.empty()){

        int m = 0,p = q.front();

        if(vis[ p ] == 0) m = 1;

        mp[ vis[ p ] ]++;

        q.pop();

        for(auto x : graph[ p ]){

            if(vis[ x ] == -1) {

                vis[ x ] = m;

                q.push( x );
            }
        }
    }
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;

    cin >> test;

    for(int t = 1; t <= test; t++){

        int n,f = 0;

        memset(vis,-1,sizeof vis);
        for(int i = 0; i < mx; i++) graph[ i ].clear();

        cin >> n;

        while(n--){

            int u,v;

            cin >> u >> v;

            //if(!f) f = u;

            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }

        int ans = 0;

        for(int i = 1; i <= mx; i++){

            if(graph[ i ].size() > 0 && vis[ i ] == -1){

                mp.clear();

                BFS( i );

                ans += max(mp[ 0 ],mp[ 1 ]);
            }
        }


//        for(int i = 1; i <= mx; i++)
//            cout << vis[ i ] << " ";
//
//        cout << endl;

        cout << "Case " << t << ": " << ans << endl;

    }

    return 0;
}
