#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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

    #ifndef ONLINE_JYUDGE
    in
    #endif // ONLINE_JYUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y[ ] = { 1,-1,0,0,-1,1,1,-1 };
int hx[ ] = { 2,2,1,1,-2,-2,-1,-1 };
int hy[ ] = { 1,-1,2,-2,1,-1,2,-2 };

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }

int n;
vector< vector< int > > graph;
vector< vector< int > > cap;

int bfs(int s,int t,vector< int > &p){

    vector< int > new_flow( p.size()+5,0 );
    fill(p.begin(),p.end(),-1);

    p[ s ] = -2;
    new_flow[ s ] = inf;

    queue< int > q;

    q.push( s );

    while( !q.empty() ){

        int node = q.front();

        q.pop();

        for(auto x : graph[ node ]){

            if(p[ x ] == -1 and cap[ node ][ x ] > 0){

                p[ x ] = node;

                new_flow[ x ] = min(new_flow[ node ],cap[ node ][ x ]);

                if(x == t) return new_flow[ x ];

                q.push( x );
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){

    int flow = 0;

    vector< int > p( n+5 );

    int new_flow;

    while( true ){

        new_flow = bfs(s,t,p);

        if(!new_flow) break;

        flow += new_flow;

        int node = t;

        while( node != s ){

            int pa = p[ node ];
            cap[ pa ][ node ] -= new_flow;
            cap[ node ][ pa ] -= new_flow;
            node = pa;
        }
    }
    return flow;
}
int main(){

  //  file();

    int t = I();

    Case( t ){

        n = I();

        vector< vector< int >  > v(n + 5);
        vector< vector< int > > v1(n+5,vector< int >( n+5,0 ));

        swap(graph,v);
        swap(cap,v1);

        int s = I(),t = I(),c = I();

        while( c-- ){

            int a = I(),b = I(),cost = I();
            graph[ a ].pb( b );
            graph[ b ].pb( a );
            cap[ a ][ b ] += cost;
            cap[ b ][ a ] += cost;
        }
        //okay
        cout << "Case " << cs << ": " << max_flow(s,t) << endl;
    }
    return 0;
}
