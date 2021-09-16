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

vector<vector< int > > graph;
int vis[ 110 ][ 3 ];

void DFS(int node,int flag){

    if(flag != -1) vis[ node ][ flag ] = 1;

    int flg = 1;

    if(flag == 1) flg = 2;

    for(auto x : graph[ node ]){

        if(!vis[ x ][ flg]) DFS(x,flg);
    }
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

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;
            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        memset(vis,0,sizeof vis);

        DFS(1,-1);

        int cnt = 0;

        for(int i = 1; i <= n; i++) if(vis[ i ][ 2 ] == 1) cnt++;

        cout << "Case " << cs << ": " << cnt << endl;
    }
    return 0;
}
