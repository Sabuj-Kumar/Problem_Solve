#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull usigned long long
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

const int N = 1e5 + 10;
vector<vector< int > > graph;
int vis[ N ];
int mx;

int level;

void DFS(int node){

    if(vis[ node ] != 0) return;

    level++;

    vis[ node ] = 1;

    mx = max(mx,level);

    for(auto x : graph[ node ]) DFS(x);
}
int main(){

    //file();

    int n = I(),m = I();

    vector< vector< int > > v1(n+5);
    vector< int > v;
    swap(graph,v1);

    while(m--){

        int a = I(),b = I();

        graph[ a ].pb( b );
        graph[ b ].pb( a );
    }

    for(int i = 0; i < n; i++){

        if(vis[ i ] == 0) {

            level = 0;

            mx = -1;

            DFS( i );

            v.pb( mx );
        }
    }

    ll sum = 0,ans = 0;

    for(int i = 0; i < v.size(); i++){

        ans += sum * v[ i ];

        sum += v[ i ];
    }

    cout << ans << endl;

    return 0;
}
