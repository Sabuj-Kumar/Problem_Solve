#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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

const int N = 1e4;
int n,q;
vector< vector< int > > graph;
int table[ N ][ 20 ];
int level[ N ];

void DFS(int node,int parent,int lv = 0){

    table[ node ][ 0 ] = parent;
    level[ node ] = lv;

    for(auto x : graph[ node ])
        if(x != parent and level[ x ] == -1)
            DFS(x,node,lv+1);
}

void sparse(){

    int lg = log2( n );

    for(int j = 0;  j <= lg; j++)
        for(int i = 1; i <= n; i++){

            level[ i ] = -1;
            table[ i ][ j ] = -1;
        }

    DFS(1,-1);

    for(int j = 1; j <= lg; j++)
        for(int i = 1; i <= n; i++)
            if(table[ i ][ j - 1 ] != -1)
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA(int u,int v){

    if(level[ u ] < level[ v ]) swap(u,v);

    int lg = log2(level[ u ]);

    for(int i = lg; i >= 0; i--)
        if(level[ u ] - (1 << i) >= level[ v ])
            u = table[ u ][ i ];

    if(u == v)return u;

    for(int i = lg; i >= 0; i--){

        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ]){

            u = table[ u ][ i ];
            v = table[ v ][ i ];
        }
    }

    return table[ u ][ 0 ];
}

int k_th(int u,int k){

    int lg = log2( level[ u ] );

    for(int i = lg; i >= 0; i--)
        if(level[ u ] - (1 << i) >= k)
            u = table[ u ][ i ];

    return u;
}
int main(){

    file();

    int a,b;

    while(cin >> n){

        if(n == 0) break;

        vector< vector< int > > v(n + 1);
        swap(v,graph);

        for(int i = 1; i < n; i++){

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        sparse();

        cin >> q;

        while(q--){

            cin >> a >> b;

            int p,lca = LCA(a,b);

            int dis = level[ a ] + level[ b ] - 2 * level[ lca ];

            if(dis & 1){

                if(level[ a ] > level[ b ]) p = k_th(a,level[ a ] - dis/2);
                else p = k_th(b,level[ b ] - dis/2);

                if(p > table[ p ][ 0 ]) printf("The fleas jump forever between %d and %d.\n",table[ p ][ 0 ],p);
                else  printf("The fleas jump forever between %d and %d.\n",p,table[ p ][ 0 ]);
            }
            else {

                if(level[ a ] > level[ b ]) p = k_th(a,level[ a ] - dis/2);
                else p = k_th(b,level[ b ] - dis/2);

                printf("The fleas meet at %d.\n",p);
            }
        }
    }

    return 0;
}
