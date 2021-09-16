#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;
    data() {}
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b ,a % b);
}

const int N = 1e3 + 5;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;

int X[ ] = {0,0,-1,1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int sc() { int n; scanf("%d",&n); return n; }

vector< vector< int > > graph;
int dp[ N ][ 5 ],parent[ N ];

int min_vertex(int node,int guard){

    if(graph[ node ].size() == 0) return 1;

    if(dp[ node ][ guard ] != -1) return dp[ node ][ guard ];

    int num = 0;

    for(auto x : graph[ node ]){

        if(x != parent[ node ]){

            parent[ x ] = node;
            if( !guard ) num += min_vertex(x,1);
            else num += min( min_vertex(x,0),min_vertex(x,1) );
        }
    }
    return dp[ node ][ guard ] = num + guard;
}
int main(){

    //file();

    int n;

    while(scanf("%d",&n)){

        if( !n ) break;

        memset(dp,-1,sizeof dp);
        Lop(i,1,N) parent[ i ] = i;
        vector< vector< int > > v( n+5 );
        swap(graph,v);

        Lop(i,1,n+1){

            int c = sc();
            while( c-- )graph[ i ].pb( sc() );
        }

        printf("%d\n",min(min_vertex(1,0),min_vertex(1,1)));
    }
    return 0;
}
