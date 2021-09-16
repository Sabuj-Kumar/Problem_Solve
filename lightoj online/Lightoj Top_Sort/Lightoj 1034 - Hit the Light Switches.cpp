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

const int N = 10010;
vector< vector< int > > graph;
bool vis[ N ];
stack< int > st;

void dfs(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    for(auto x : graph[ node ]) dfs( x );

    st.push( node );
}

void DFS(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    for(auto x : graph[ node ]) DFS( x );
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        int n,m;

        cin >> n >> m;

        vector< vector< int > > v(n+5);
        swap(graph,v);
        while(!st.empty()) st.pop();

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
        }

        memset(vis,false,sizeof vis);

        for(int i = 1; i <= n; i++)
            if(vis[ i ] == false) dfs( i );

        memset(vis,false,sizeof vis);

        int sz = st.size(),ans = 0;

        for(int i = 0; i < sz; i++){

            int n = st.top();

            st.pop();

            if(!vis[ n ]){

                ans++;

                DFS( n );
            }
        }

        cout << "Case " << cs << ": " << ans << endl;
    }
    return 0;
}
