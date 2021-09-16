#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
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
vector< int > graph[ N ];
int n,m,subtree[ N ];

int long_path(int node){

    if(subtree[ node ] != 0) return subtree[ node ];

    subtree[ node ] = 1;

    int mx = -1;

    for(auto x : graph[ node ]){

        int n = long_path( x );

        if(mx < n) mx = n;
    }

    if(mx > -1) subtree[ node ] += mx;

    return subtree[ node ];
}
int main(){

    //file();

    cin >> n >> m;

    while(m--){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
    }

    int mx = -1;

    for(int i = 1; i <= n; i++) {

        int n = long_path( i );

        if(n > mx) mx = n;
    }

    cout << mx - 1 << endl;

    return 0;
}
