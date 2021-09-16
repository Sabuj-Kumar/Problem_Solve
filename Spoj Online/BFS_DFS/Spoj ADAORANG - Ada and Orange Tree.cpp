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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 5e5 + 10;
vector< int > v;
int n,q,r;
vector< int > graph[ N ];
int lg,table[ N ][ 30 ];
int level[ N ];
bitset< 255 > vis[ N ];

void dfs(int chaild,int baba,int lv){

    table[ chaild ][ 0 ] = baba;
    level[ chaild ] = lv;
    vis[ chaild ][ v[ chaild ] ] = 1;

    for(auto x : graph[ chaild ])
        if(x != chaild and level[ x ] == -1){
             dfs(x,chaild,lv+1);
             vis[ chaild ] |= vis[ x ];
        }

}
void sparse(int root){

    lg = log2( n );

    for(int j = 0; j <= lg; j++)
        for(int i = 0; i < n; i++)
            table[ i ][ j ] = -1;

    dfs(root,-1,0);

    for(int j = 1; j <= lg; j++)
        for(int i = 0; i < n; i++)
            if(table[ i ][ j - 1 ] != -1)
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA(int u,int v){

    if(level[ u ] < level[ v ]) swap(u,v);

    lg = log2( level[ u ] );

    for(int i = lg; i >= 0; i--)
        if(level[ u ] - (1 << i) >= level[ v ])
            u = table[ u ][ i ];

    if(u == v) return u;

    for(int i = lg; i >= 0; i--)
        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ])
            u = table[ u ][ i ],v = table[ v ][ i ];

    return table[ u ][ 0 ];
}

void init(){

    for(int i = 0; i < N; i++){

        graph[ i ].clear();
        level[ i ] = -1;
        vis[ i ].reset();
    }
    v.clear();
}
int main(){

    file();

    int t = I();

    while( t-- ){

        init();

        n = I();
        q = I();
        r = I();

        for(int i = 0; i < n; i++) v.pb( I() );

        for(int i = 1; i < n; i++){

            int a = I();
            int b = I();

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        sparse( r );

        while(q--){

            int a = I();
            int b = I();

            int lca = LCA(a,b);

            vis[ lca ][ v[ lca ] ] = 1;

            cout << vis[ lca ].count() << endl;
        }
    }
    return 0;
}
