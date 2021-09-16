#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long mn,sum;
bool vis[ N ];

vector< int > p,c;
vector< int > graph[ N ];

int dfs(int node,int root){

    if(vis[ node ]) return 0;

    vis[ node ] = 1;

    int sub = 0;

    sub = node;

    for(auto x : graph[ node ]){

        sub += dfs( x,root );

        cout << "sub " << sub << endl;
    }

    return sub;
}
int main(){

    freopen("in.txt","r",stdin);

    for(int i = 0; i < N; i++) graph[ i ].clear();
    memset(vis,0,sizeof vis);
    mn = INT_MAX;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {

        int a;
        cin >> a;
        p.push_back( a );
    }

    cin >> n;

    sum = 0;

    for(int i = 0; i < n; i++) {

        int a;
        cin >> a;
        c.push_back( a );

        sum += a;
    }

    cout << "sum " << sum << endl;

    for(int i = 1; i < n; i++){

        graph[ c[ p[ i ] ] ].push_back(c[ i ]);
        graph[ c[ i ] ].push_back(c[ p[ i ] ]);
    }

    dfs(c[ 0 ],c[ 0 ]);

    cout << mn << endl;

    return 0;
}
