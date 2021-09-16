#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % n) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int I() { int n; sc( n ); return n; }
ll Il() { ll n;  sl( n ); return n; }

int n;
int cost[ 2 * 110 ][ 2 * 110 ];
vector< int > node_cost;
vector< vector< int > > graph;

int bfs(int s,int d,vector< int > &p){

    fill(p.begin(),p.end(),-1);

    p[ s ] = -2;

    queue< pii > q;

    q.push( {s,inf} );

    while( !q.empty() ){

        int node = q.front().f;
        int flow = q.front().s;

        q.pop();

        for(auto x : graph[ node ]){

            if( p[ x ] == -1 and cost[ node ][ x ] > 0 ){

                p[ x ] = node;

                int new_flow = min(flow,cost[ node ][ x ]);

                if(x == d) return new_flow;

                q.push({x,new_flow});
            }
        }
    }
    return 0;
}
int max_flow(int s,int d){

    vector< int > p(2 * d + 5);

    int flow = 0,new_flow = inf;

    while( new_flow = bfs(s,d,p) ){

        flow += new_flow;

        int node = d;

        while( node != s ){

            int pa = p[ node ];

            cost[ pa ][ node ] -= new_flow;
            cost[ node ][ pa ] += new_flow;

            node = pa;
        }
    }
    return flow;
}
int main(){

    file();

    int t = I();

    Case( t ){

        n = I();
        int des = 2 * n + 5;
        vector< vector< int > > v1(2 * (n + 5) );
        swap(v1,graph);
        memset(cost,0,sizeof cost);

        lop(i,1,n+1) {

            int c = I();

            int x = 2 * i;
            int y = 2 * i + 1;

            graph[ x ].pb( y  );
            graph[ y ].pb( x  );

            cost[ x ][ y ] += c;
            cost[ y ][ x ] += 0;
        }

        int edge = I();

        while( edge-- ){

            int a = I(),b = I(),c = I();

            int x = 2 * a + 1;
            int y = 2 * b;

            graph[ x ].pb( y );
            graph[ y ].pb( x );

            cost[ x ][ y ] += c;
            cost[ y ][ x ] += 0;
        }

        int b = I(),d = I();

        lop(i,0,b){

            int a = I();
            int x = 2 * a;

            graph[ 0 ].pb( x );
            graph[ x ].pb( 0 );

            cost[ 0 ][ x ] += inf;
            cost[ x ][ 0 ] += 0;
        }
        lop(i,0,d){

            int a = I();
            int x = 2 * a + 1;

            graph[ x ].pb( des );
            graph[ des ].pb( x );

            cost[ x ][ des ] += inf;
            cost[ des ][ x ] += 0;
        }

        printf("Case %d: %d\n",cs,max_flow( 0,des ) );
    }
    return 0;
}
