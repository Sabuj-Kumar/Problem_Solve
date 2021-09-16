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

const int N = 10100;
const int mod = 1000000007;
vector< vector< int > > graph;
ll dp[ N ];
bool vis[ N ];
int s,d;

ll count_paths(int node){

    if(node == d) return 1;
    if(graph[ node ].size() == 0) return 0;
    if(vis[ node ]) return dp[ node ];

    vis[ node ] = true;

    ll res = 0;

    for(auto x : graph[ node ]) res = (res+count_paths( x )) % mod;

    return dp[ node ] = res;
}

int main(){

    //file();

    int t;

    cin >> t;

    while(t--){

        int n,m;

        cin >> n >> m >> s >> d;

        vector< vector< int > > v( n + 5 );

        swap(v,graph);

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
        }

        ll paths = 0;

        memset(vis,false,sizeof vis);

        paths = count_paths( s );

        cout << paths << endl;
    }

    return 0;
}
