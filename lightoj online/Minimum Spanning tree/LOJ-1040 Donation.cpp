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
#define in freopen("input.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

struct Node{

    int x;
    int y;
    int c;

    Node(int x_,int y_,int c_) { x = x_; y = y_; c = c_; }
};

vector< Node > edge;
vector< vector< int > > graph;
int parent[ 55 ];
bool vis[ 55 ];

int n,ln;

bool cmp(Node a,Node b){

    return a.c < b.c;
}

void DFS(int node){

    if(vis[ node ]) return;

    ln++;

    vis[ node ] = true;

    for(auto x : graph[ node ]) DFS( x );
}
int find_parent(int p){

    if(p == parent[ p ]) return p;
    return parent[ p ] = find_parent( parent[ p ] );
}

int MST(){

    for(int i = 1; i <= 50; i++) parent[ i ] = i;

    sort(edge.begin(),edge.end(),cmp);

    int sz = edge.size(),l = 0,mst = 0,ed = n - 1;

    while(l < sz and ed){

        int a = edge[ l ].x;
        int b = edge[ l ].y;

        int p = find_parent( a );
        int q = find_parent( b );

        if(p != q){

            parent[ q ] = p;

            mst += edge[ l ].c;

            ed--;
        }

        l++;
    }

    return mst;
}

bool check(int node){

    ln = 0;

    memset(vis,false,sizeof vis);

    DFS( node );

    return ln == n;
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> n;
        vector< vector< int > > v(n + 5);
        vector< Node > ed;
        swap(v,graph);
        swap(ed,edge);

        int total = 0;

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= n; j++){

                int w;

                cin >> w;

                if( w ){

                    edge.pb(Node(i,j,w));

                    graph[ i ].pb( j );
                    graph[ j ].pb( i );

                    total += w;
                }
            }
        }

        cout << "Case " << cs << ": ";

        if(!check( 1 )){

            cout << -1 << endl;

            continue;
        }

        int mst = MST();

        cout << total - mst << endl;
    }

    return 0;
}
