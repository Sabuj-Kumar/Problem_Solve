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
int parent[ 110 ];
bool vis[ 110 ];

int ln,m;

bool cmp(Node a,Node b){

    return a.c < b.c;
}

void DFS(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    for(auto x : graph[ node ]) DFS( x );
}
int find_parent(int p){

    if(p == parent[ p ]) return p;
    return parent[ p ] = find_parent( parent[ p ] );
}

int MST(int n){

    vector< vector< int > > v(n + 5);
    swap(v,graph);

    for(int i = 1; i <= 110; i++) parent[ i ] = i;

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

            graph[ a ].pb( b );
            graph[ b ].pb( a );

            ed--;
        }

        l++;
    }

    return mst;
}

int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> m;

        vector< Node > edg;
        swap(edg,edge);

        string s1,s2;
        int cost,ed = 0;

        unordered_map< string ,int > mp;

        for(int i = 1; i <= m; i++){

            cin >> s1;
            cin >> s2;
            cin >> cost;

            if(mp[ s1 ] == 0) mp[ s1 ] = ++ed;

            if(mp[ s2 ] == 0) mp[ s2 ] = ++ed;

            edge.pb(Node(mp[ s1 ],mp[ s2 ],cost));
        }

        int mst = MST(ed);

        memset(vis,false,sizeof vis);

        DFS( 1 );

        bool flag = false;

        for(int i = 1; i <= ed; i++) {

            if(vis[ i ] == false){

                flag = true;

                break;
            }
        }

        cout << "Case " << cs << ": ";

        if(flag) cout << "Impossible" << endl;

        else cout << mst << endl;
    }

    return 0;
}

