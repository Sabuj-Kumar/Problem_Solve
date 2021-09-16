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

const int N = 10010;
int n;
int lv,nd;
bool vis[ N ];
vector< vector< int > > graph;

void DFS(int node,int level){

    if(vis[ node ]) return;

    vis[ node ] = true;

    if(level > lv){

        lv = level;
        nd = node;
    }

    for(auto x : graph[ node ]) DFS( x,level+1);
}
int main(){

    file();

    cin >> n;

    vector< vector< int > > v(n + 5);

    swap(v,graph);

    for(int i = 1; i < n; i++){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
        graph[ b ].pb( a );
    }

    nd = 0;
    lv = -1;

    DFS( 1,0);

    lv = -1;

    for(int i = 1; i <= n; i++) vis[ i ] = false;

    DFS( nd,0);

    cout << lv << endl;

    return 0;
}
