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

const int N = 1e5 + 10;
ull cnt,n,m,l,r;
vector< ull > graph[ N ];
bool vis[ N ];

void DFS(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    cnt++;

    for(auto x : graph[ node ])  DFS( x );
}
int main(){

    //file();

    ull t;

    cin >> t;

    while(t--){

        cin >> n >> m >> l >> r;

        for(int i = 0; i < m; i++){

            ull a,b;
            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        ull ans = 0;

        if(l <= r) ans = n * l;

        else{

            ans = 0;

            for(int i = 1; i <= n; i++){

                if(!vis[ i ]){

                    cnt = 0;

                    DFS( i );

                    ans += l + (cnt - 1) * r;
                }
            }
        }

        cout << ans << endl;

        memset(vis,false,sizeof vis);
        for(int i = 0; i <= N; i++) graph[ i ].clear();
    }

    return 0;
}
