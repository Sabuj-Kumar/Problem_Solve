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

const int N = 100010;
int n,q,lg;
int table[ N ][ 20 ],mn[ N ][ 20 ],mx[ N ][ 20 ];
int level[ N ];
vector<vector< pii > > graph;

void dfs(int node,int p,int weight,int lv = 0){

    table[ node ][ 0 ] = p;
    level[ node ] = lv;
    mx[ node ][ 0 ] = weight;
    mn[ node ][ 0 ] = weight;

    for(auto x : graph[ node ])
        if(level[ x.ft ] == -1 and x.ft != p)
            dfs(x.ft,node,x.sd,lv+1);
}
void sparse(){

    for(int j = 0; j <= lg; j++){

        for(int i = 1; i <= n; i++){

            table[ i ][ j ] = -1;
            mx[ i ][ j ] = INT_MIN;
            mn[ i ][ j ] = INT_MAX;
        }
    }

    dfs(1,-1,0);

    for(int j = 1; j <= lg; j++){

        for(int i = 1; i <= n; i++){

            if(table[ i ][ j - 1 ] != -1){

                mx[ i ][ j ] = max(mx[ i ][ j - 1 ],mx[ table[ i ][ j - 1 ] ][ j - 1 ]);
                mn[ i ][ j ] = min(mn[ i ][ j - 1 ],mn[ table[ i ][ j - 1 ] ][ j - 1 ]);
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
            }
        }
    }
}
pii LCA(int u,int v){

    int mxi = INT_MIN,mni = INT_MAX;

    if(level[ u ] < level[ v ]) swap(u,v);

    lg = log2(level[ u ]);

    for(int i = lg; i >= 0; i--){
        if(level[ u ] - (1 << i) >= level[ v ]){

            mxi = max(mxi,mx[ u ][ i ]);
            mni = min(mni,mn[ u ][ i ]);
            u = table[ u ][ i ];
        }
    }

    if(u == v) return {mni,mxi};

    for(int i = lg; i >= 0; i--){

        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ]){

            mxi = max(mxi,max(mx[ u ][ i ],mx[ v ][ i ]));
            mni = min(mni,min(mn[ u ][ i ],mn[ v ][ i ]));
            u = table[ u ][ i ];
            v = table[ v ][ i ];
        }
    }

    mxi = max( mxi,max(mx[ u ][ 0 ],mx[ v ][ 0 ]));
    mni = min( mni,min(mn[ u ][ 0 ],mn[ v ][ 0 ]));

    return {mni,mxi};
}
int main(){

    file();

    memset(level,-1,sizeof level);

    cin >> n;
    vector<vector< pii > > v(n+5);
    swap(graph,v);
    lg = log2( n );

    for(int i = 1; i < n; i++){

        int a,b,c;

        cin >> a >> b >> c;

        graph[ a ].pb({b,c});
        graph[ b ].pb({a,c});
    }

    sparse();

    int q;

    cin >> q;

    while( q-- ){

        int a,b;

        cin >> a >> b;

        pii ans = LCA(a,b);

        cout << ans.ft << " " << ans.sd << endl;
    }

    return 0;
}
