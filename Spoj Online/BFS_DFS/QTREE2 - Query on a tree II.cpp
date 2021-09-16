#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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

const int N =  100100;
vector< vector< pll > > graph;
int lg,n;
int table[ N ][ 20 ],level[ N ];
ll cost[ N ];

void DFS(int child,int parent,int lv,ll weight){

    table[ child ][ 0 ] = parent;
    level[ child ] = lv;
    cost[ child ] = weight;

    for(auto x : graph[ child ])
        if(level[ x.ft ] == -1 and x.ft != parent)
            DFS(x.ft,child,lv+1,weight+x.sd);
}
void sparse(){

    for(int j = 0; j <= lg; j++)
        for(int i = 0; i <= n; i++)
            table[ i ][ j ] = -1;

    DFS(1,-1,0,0);

    for(int j = 1; j <= lg; j++)
        for(int i = 1; i <= n; i++)
            if(table[ i ][ j - 1 ] != -1)
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA(int u,int v){

    if(level[ u ] < level[ v ]) swap(u,v);

    lg = 1;

    while((1 << lg) <= level[ u ]) ++lg;

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

int Kth_Parent(int u,int k){

    for(int i = lg; i >= 0; i--){

        if(k & (1 << i)){

            u = table[ u ][ i ];

            if(u == -1) break;
        }
    }
    return u;
}
int main(){

    file();

    int t;
    bool fg = 0;

    cin >> t;

    while(t--){

        if(fg) puts("");
        fg = 1;

        cin >> n;

        vector< vector< pll > > v(n + 5);
        swap(v,graph);
        memset(level,-1,sizeof level);

        for(int i = 1; i < n; i++){

            int a,b,w;

            cin >> a >> b >> w;

            graph[ a ].pb({b,w});
            graph[ b ].pb({a,w});
        }

        while((1 << lg) <= n) lg++;

        sparse();

        string s;

        while(cin >> s){

            if(s == "DONE") break;

            if(s == "DIST"){

                int a,b;

                cin >> a >> b;

                int lca = LCA(a,b);

                cout << cost[ a ] + cost[ b ] - (2 * cost[ lca ]) << endl;
            }
            else {

                int a,b,k;

                cin >> a >> b >> k;

                k--;

                int lca = LCA(a,b);
                int left = level[ a ] - level[ lca ];
                int right = level[ b ] - level[ lca ];

                if(k <= left) cout << Kth_Parent(a,k) << endl;
                else{

                    k = k - left;
                    k = right - k;

                    cout << Kth_Parent(b,k) << endl;
                }
            }
        }
    }

    return 0;
}
