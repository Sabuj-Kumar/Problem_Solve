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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 1e5 + 10;
vector<vector< int > > graph;
int vis[ N ];
int mx,node;

void BFS(int root){

    mx = -1;

    memset(vis,-1,sizeof vis);

    vis[ root ] = 0;

    queue< int > q;

    q.push( root );

    while(!q.empty()){

        int p = q.front();

        q.pop();

        if(vis[ p ] > mx){

            mx = vis[ p ];

            node = p;
        }

        for(auto x : graph[ p ]){

            if(vis[ x ] == -1){

                vis[ x ] = vis[ p ] + 1;

                q.push( x );
            }
        }
    }
}
int main(){

    //file();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;
        vector< vector< int > > v( n );
        swap(graph,v);

        for(int i = 1; i < n; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        BFS( 0 );

        BFS( node );

        cout << ceil((db)mx/2.0) << endl;
    }
    return 0;
}
