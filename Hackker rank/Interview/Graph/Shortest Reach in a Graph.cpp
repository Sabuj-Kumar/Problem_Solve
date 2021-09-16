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
#define lop(i,vis,n) for(int i = vis; i < n; i++)
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

vector< vector< int > > graph;
vector< int > vis;

void BFS(int s){

    queue< int > q;

    q.push( s );

    vis[ s ] = 0;

    while(!q.empty()){

        int u = q.front();

        q.pop();

        for(auto v : graph[ u ]){

            if(vis[ v ] == -1){

                vis[ v ] = vis[ u ] + 6;

                q.push( v );
            }
        }
    }
}

int main(){

   // file();

    int t;

    cin >> t;

    while(t--){

        int n,m,s;

        cin >> n >> m;

        vector< vector< int > > v(n+1,vector< int >());
        vector< int > c(n+1,-1);
        swap(v,graph);
        swap(c,vis);

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        cin >> s;

        BFS( s );

        for(int i = 1; i <= n; i++){

            if(i == s) continue;

            cout << vis[ i ];

            if(i < n) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
