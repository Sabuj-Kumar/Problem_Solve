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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 3000;
int n,m;
vector< vector< int > > graph;
int vis[ N ];
bool flag;

void BFS(int root){

    int bp = 0;

    vis[ root ] = 0;

    queue< int > q;

    q.push( root );

    while( !q.empty() ){

        int p = q.front();

        q.pop();

        bp = vis[ p ] == 0 ? 1 : 0;

        for(auto x : graph[ p ]){

            if(x == p) continue;

            if(vis[ x ] == -1) {

                vis[ x ] = bp;
                q.push( x );
            }
            else if(vis[ x ] == vis[ p ]) flag = false;
        }
    }
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        memset(vis,-1,sizeof vis);

        cin >> n >> m;
        vector< vector< int > > v( n + 5 );
        swap(graph,v);

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

//        for(int i = 1; i <= n; i++){
//
//            cout << i << ": ";
//
//            for(auto x : graph[ i ]) cout << x << " ";
//
//            cout << endl;
//        }
//
//        cout << endl;
        flag = true;

        for(int i = 1; i <= n; i++){

            if(vis[ i ] == -1) BFS( i );
        }

        cout << "Scenario #" << cs <<":" << endl;

        if(flag) cout << "No suspicious bugs found!";
        else cout << "Suspicious bugs found!";

        cout << endl;
    }
    return 0;
}
