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

const int N = 5e3;

ll n,m,s;
ll parent[ N ];
vector< vector< pll > > graph;
priority_queue< pll,vector< pll> ,greater< pll > > q;

void init_(ll n) { for(ll i = 1; i <= n; i++) parent[ i ] = i; }
ll search_parent(ll p){ return parent[ p ] == p ?  p : parent[ p ] = search_parent( parent[ p ] ); }
void union_(ll x,ll y){ parent[ x ] = y; }

void MST(ll source,ll edge){




}
int main(){

    file();

    cin >> n >> m;

     init_( n );

    vector< vector< pii > > v(n + 5);

    for(int i = 0; i < m; i++){

        int a,b,c;

        cin >> a >> b >> c;

        graph[ a ].pb({c,b});
        graph[ b ].pb({c,a});
    }

    cin >> s;



    return 0;
}
