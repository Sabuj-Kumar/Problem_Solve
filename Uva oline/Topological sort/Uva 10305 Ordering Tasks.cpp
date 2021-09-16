#include<bits/stdc++.h>

using namespace std;

vector< int > graph[ 110 ];
stack< int > st;
bool vis[ 110 ];

void DFS(int n){

    if(vis[ n ]) return;

    vis[ n ] = true;

    for(auto x : graph[ n ]) DFS( x );

    st.push( n );
}
int main(){

    //freopen("input.txt","r",stdin);

    int n,m;

    while(cin >> n >> m){

        if(n == 0 && m == 0) break;

        memset(vis,false,sizeof vis);
        for(int i = 0; i < 110; i++) graph[ i ].clear();

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].push_back( b );
        }

        for(int i = 1; i <= n; i++)
            if(!vis[ i ]) DFS( i );

        while(!st.empty()){

            cout << st.top();

            st.pop();

            if(st.size() > 0) cout << " ";
        }

        cout << endl;
    }

    return 0;
}
