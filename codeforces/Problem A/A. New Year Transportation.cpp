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

const int N = 4 * 1e4;
vector< int > graph[ N ];
bool vis[ N ];
int n,t;
bool flg;

void DFS(int node){

    vis[ node ] = true;

    if(vis[ t ]) {

        flg = true;
        return;
    }

    for(auto x : graph[ node ]){

        if(vis[ t ]) return;
        if(!vis[ x ]) DFS( x );
    }
}
int main(){

    //file();

    cin >> n >> t;

    for(int i = 1; i < n; i++){

        int a;

        cin >> a;

        graph[ i ].pb( i + a );
    }

    flg = false;

    DFS( 1 );

    if(flg) puts("YES");
    else puts("NO");

    return 0;
}
