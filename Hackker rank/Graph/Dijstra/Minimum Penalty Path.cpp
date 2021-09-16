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

int n,m;
const ll N = 1e4+10;

vector< pll > graph[ N ];
bool vis[ N ][ N ];

void BFS(ll a){

    queue< pll > q;

    q.push({a,0});

    while( !q.empty() ){

        pll p = q.front();

        q.pop();

        vis[ p.ft ][ p.sd ] = true;

        for(auto x : graph[ p.ft ])
        if(!vis[ x.ft ][ x.sd | p.sd ]){

            vis[ x.ft ][ x.sd | p.sd ] = true;

            q.push({x.ft,(x.sd | p.sd)});
        }
    }
}
int main(){

    file();

    cin >> n >> m;
    ll a,b,c;

    for(int i = 0; i < m; i++){

        cin >> a >> b >> c;

        graph[ a ].pb({b,c});
        graph[ b ].pb({a,c});
    }

    cin >> a >> b;

    BFS( a );

    ll ans = -1;

    for(ll i = 1; i < 1024; i++){

        if(vis[ b ][ i ] == true){

            ans = i;

            break;
        }
    }

    cout << ans << endl;

    return 0;
}
