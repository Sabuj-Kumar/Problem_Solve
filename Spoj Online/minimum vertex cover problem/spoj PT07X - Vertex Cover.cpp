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
    data(){}
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a)const{

        return c > a.c;
    }
};

const int N = 1e5 + 5;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int sc() {int v; scanf("%d",&v); return v; }

vector< int > graph[ N ];
int parent[ N ],dp[ N ][ 5 ];

int min_vertex(int node,int guard){

    if(graph[ node ].size() == 0) return 0;
    if(dp[ node ][ guard ] != -1) return dp[ node ][ guard ];

    int num = 0;

    for(auto x : graph[ node ]){

        if(x != parent[ node ]){

            parent[ x ] = node;
            if( !guard ) num += min_vertex(x,1);
            else num += min(min_vertex(x,0),min_vertex(x,1));
        }
    }
    return dp[ node ][ guard ] = num + guard;
}

int main(){

    memset(dp,-1,sizeof dp);

    int n;

    scanf("%d",&n);
    n--;

    while( n-- ){

       int a,b;
       scanf("%d %d",&a,&b);
       graph[ a ].pb( b );
       graph[ b ].pb( a );
    }
    int ans = 0;
    ans = min(min_vertex(1,0),min_vertex(1,1));

    printf("%d\n",ans);

    return 0;
}
