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

const int N =  101000;
const int mod = 1000000007;

ll dp[ 11 ][ N ];
bool vis[ 11 ][ N ];
vector< ll > graph[ 11 ];

void pre(){

    graph[ 0 ].pb( 7 );
    graph[ 1 ].pb( 2 );
    graph[ 1 ].pb( 4 );
    graph[ 2 ].pb( 1 );
    graph[ 2 ].pb( 3 );
    graph[ 2 ].pb( 5 );
    graph[ 3 ].pb( 2 );
    graph[ 3 ].pb( 6 );
    graph[ 4 ].pb( 1 );
    graph[ 4 ].pb( 5 );
    graph[ 4 ].pb( 7 );
    graph[ 5 ].pb( 2 );
    graph[ 5 ].pb( 4 );
    graph[ 5 ].pb( 6 );
    graph[ 5 ].pb( 8 );
    graph[ 6 ].pb( 3 );
    graph[ 6 ].pb( 5 );
    graph[ 6 ].pb( 9 );
    graph[ 7 ].pb( 0 );
    graph[ 7 ].pb( 4 );
    graph[ 7 ].pb( 8 );
    graph[ 8 ].pb( 5 );
    graph[ 8 ].pb( 7 );
    graph[ 8 ].pb( 9 );
    graph[ 9 ].pb( 6 );
    graph[ 9 ].pb( 8 );
}

ll DP_Cal(ll node,ll rem){

    if(vis[ node ][ rem ]) return dp[ node ][ rem ];

    vis[ node ][ rem ] = true;

    if(!rem) return dp[ node ][ rem ] = 1;

    ll res = 0;

    for(auto x : graph[ node ]) res = (res + DP_Cal(x,rem - 1 )) % mod;

    return dp[ node ][ rem ] = res;
}
int main(){

    pre();

   // file();

    int t;

    cin >> t;

    while(t--){

        ll n;

        cin >> n;

        ll ans = 0;

        for(ll i = 0; i < 10; i++) ans = ( ans + DP_Cal( i , n - 1 ) ) % mod;

        cout << ans << endl;
    }
    return 0;
}
