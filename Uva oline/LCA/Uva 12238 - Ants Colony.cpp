#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e5+100;
ll table[ N ][ 30 ],cost[ N ];
int n,level[ N ];
vector< vector< pii > > graph;

void DFS(int node,int p,int lv = 0){

    table[ node ][ 0 ] = p;
    level[ node ] = lv;

    for(auto x : graph[ node ])
        if(x.ft != p and level[ x.ft ] == -1){

            cost[ x.ft ] = cost[ node ] + x.sd;
            DFS(x.ft,node,lv+1);
        }
}

void sparse(){

    int lg = log2(n);

    for(int j = 0; j <= lg; j++){

        for(int i = 0; i < n; i++){

            table[ i ][ j ] = -1;
            cost[ i ] = 0;
            level[ i ] = -1;
        }
    }

    DFS(0,-1,0);

    for(int j = 1; j <= lg; j++)
        for(int i = 0; i < n; i++)
            if(table[ i ][ j - 1 ] != -1)
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA(int u,int v){

    if(level[ u ] < level[ v ]) swap(u,v);

    int lg = log2(level[ u ]);

    for(int i = lg; i >= 0; i--)
        if(level[ u ] - (1 << i) >= level[ v ])
            u = table[ u ][ i ];

    if(u == v) return u;

    for(int i = lg; i >= 0; i--){

        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ]){

            u = table[ u ][ i ];
            v = table[ v ][ i ];
        }
    }

    return table[ u ][ 0 ];
}
int main(){

    file();

    while(cin >> n and n){

        vector< vector< pii > > v(n+5);
        swap(graph,v);

        for(int i = 1; i < n; i++){

            int a,c;

            cin >> a >> c;

            graph[ i ].pb({a,c});
            graph[ a ].pb({i,c});
        }

        sparse();

        int q;

        cin >> q;

        bool flag = false;

        while(q--){

            int a,b;

            if(flag) cout << " ";
            flag = true;

            cin >> a >> b;

            int lca = LCA(a,b);

            cout << cost[ a ] + cost[ b ] - 2 * cost[ lca ];
        }
        cout << endl;
    }

    return 0;
}
