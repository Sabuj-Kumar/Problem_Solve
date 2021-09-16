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

const int N = 1010;

vector< int > graph[ N ];
int vis[ N ];

void BFS(int root){

    queue< int > q;

    q.push( root );

    vis[ root ] = 0;

    while( !q.empty() ){

        int p = q.front();

        q.pop();

        for(auto x : graph[ p ]){

            if(vis[ x ] == -1){

                vis[ x ] = vis[ p ] + 1;

                q.push( x );
            }
        }
    }
}
int main(){

    file();

    int t;

    cin >> t;

    while( t-- ){

        int n,m,a,b;

        cin >> n >> m;

        for(int i = 0; i < N; i++) graph[ i ].clear();
        memset(vis,-1,sizeof vis);

        for(int i = 0; i < m; i++){

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        cin >> a;
        bool f = false;

        BFS( a );

        for(int i = 1; i <= n; i++) {

            if( f and i != a) cout << " ";

            if(vis[ i ] != -1 and vis[ i ] != 0) { cout << vis[ i ] * 6; f = true; }
            else if(i != a) { cout << -1; f = true; }
        }

        cout << endl;
    }
    return 0;
}
