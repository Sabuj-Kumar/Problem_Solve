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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e4 + 10;
vector< ll > graph[ N ];
ll n,m;
ll vis[ N ];

ll BFS(ll root){

    queue< ll > q;

    vis[ root ] = 0;

    q.push( root );

    while( !q.empty() ){

        ll p = q.front();

        q.pop();

        if(p == n) return vis[ p ];

        for(auto x : graph[ p ])
            if(vis[ x ] == -1){
                vis[ x ] = vis[ p ] + 1;
                q.push( x );
            }
    }

    return vis[ n ];
}

int main(){

    file();

    int c;

    cin >> c;

    while( c-- ){

        memset(vis,-1,sizeof vis);
        for(int i = 0; i < N; i++) graph[ i ].clear();

        cin >> n >> m;

        for(int i = 0; i < m; i++){

            ll a,b;
            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        cout << BFS( 1 ) << endl;
    }
    return 0;
}
