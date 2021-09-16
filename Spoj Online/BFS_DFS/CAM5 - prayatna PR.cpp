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

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 100010;
vector<vector< int > > graph;
int vis[ N ];

void DFS(int node){

    vis[ node ] = true;
    for(auto x : graph[ node ])
        if(!vis[ x ]) DFS( x );
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        memset(vis,false,sizeof vis);

        int n,m;

        cin >> n >> m;
        vector<vector< int > > v( n + 5 );
        swap(v,graph);

        if(m == 0) cout << n << endl;

        else{

            int a,b;

            for(int i = 0; i < m; i++){

                cin >> a >> b;

                graph[ a ].pb( b );
                graph[ b ].pb( a );
            }

            int cnt = 0;

            for(int i = 0; i < n; i++){

                if(!vis[ i ]){

                    cnt++;

                    DFS(i);
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
