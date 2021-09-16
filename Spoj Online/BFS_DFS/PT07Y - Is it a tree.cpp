#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long long
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

    #ifndef OINLINE_JUDGE
    in;
    #endif // OINLINE_JUDGE
}
int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 10010;
vector< vector< int > > graph;
bool flag,vis[ N ];

void DFS(int node){

    vis[ node ] = true;

    for(auto x : graph[ node ]){

        if(vis[ x ]){

            flag = true;

            return;
        }

        if(flag) return;

        DFS( x );
    }
}
int main(){

    file();

    int n,m;

    cin >> n >> m;

    vector< vector< int > > v( n + 5 );
    swap(v,graph);

    for(int i = 0; i < m; i++){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
    }

    flag = false;

    DFS( 1 );

    for(int i = 1; i <= n; i++){

        if(vis[ i ] == false){

            flag = true;

            break;
        }
    }

    if(flag) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
