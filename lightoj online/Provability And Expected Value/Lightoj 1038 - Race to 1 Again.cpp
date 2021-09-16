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

const int N = 1e5 + 5;
bool vis[ N ];
db dp[ N ];
vector< int > v[ N ];

void div(){

    for(int i = 2; i < N; i++)
        for(int j = i; j < N; j += i)
            v[ j ].pb( i );
}

db DP(int n){

    if(n == 1) return 0.0;

    if(vis[ n ]) return dp[ n ];

    vis[ n ] = 1;

    int cnt = v[ n ].size()+1;

    db p = 0.0;

    for(int i = 0; i < cnt-2; i++) p += DP( v[ n ][ i ] );

    return dp[ n ] = (cnt + p) / (1.0 * (cnt-1));
}
int main(){

    op;
    div();

    file();

    int t;

    cin >> t;

    Case( t ){

        int n;

        cin >> n;

        db ans = DP( n );

        cout << fixed << setprecision(10);
        cout << "Case " << cs << ": "<< ans << endl;

        memset(vis,false,sizeof vis);
    }

    return 0;
}
