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
#define sl( n ) scanf("I64d",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 2 * 1e5 + 10;

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,m;

vector< vector< int >> graph;
vector< pii > out;
int vis[ N ];
bool flag;
vector< int > ar;

void dfs(int node){

    vis[ node ] = 1;

    for(auto x : graph[ node ]){

        if(vis[ x ] == 2) continue;
        if(vis[ x ] == 1) {

            flag = true;
            return;
        }

        dfs( x );
    }

    vis[ node ] = 2;
    ar.pb( node );
}

int main(){

    op;
    file();

    int t;

    cin >> t;

    while( t-- ){

        cin >> n >> m;

        memset(vis,0,sizeof vis);
        ar.clear();
        out.clear();

        vector< vector< int > > v( n+5 );
        swap(graph,v);
        vector< pii > edge;

        flag = false;

        for(int i = 0; i < m; i++){

            int a,b,c;
            cin >> c >> a >> b;

            if( c ) {

                graph[ a ].pb( b );

                out.pb({a,b});
            }
            else edge.pb({a,b});
        }

        for(int i = 1; i <= n; i++) if(vis[ i ] == 0) dfs( i );

        if(flag) {

            cout << "NO" << endl;
            continue;
        }

        int ind[ ar.size() + 5 ];

        for(int i = 0; i < ar.size(); i++) ind[ ar[ i ] ] = i;

        for(auto x : edge){

            if(ind[ x.ft ] < ind[ x.sd ]) swap(x.ft,x.sd);

            out.pb( x );
        }

        cout << "YES" << endl;

        for(int i = 0; i < out.size(); i++) cout << out[ i ].ft << " " << out[ i ].sd << endl;
    }

    return 0;
}
