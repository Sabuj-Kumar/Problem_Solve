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
#define sdl( n ) scanf("%lf",&n)
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

struct Data{

    int x,y,c;

    Data() {}
    Data(int x) { this -> x = x; }
    Data(int x,int y) { this -> x = x,this -> y = y; }
    Data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const Data &a) const{

        return c > a.c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}
ll big(ll n,ll p){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2);
        return ( x * x) % mod;
    }
    return ( ( n % mod ) * big(n,p-1) % mod) % mod;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,m,sz,len;
string s[ 25 ];
vector< pii > v;
int vis[ 17 ][ 22 ][ 22 ];
int dp[ 1 << 16 ][ 22 ];

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
void bfs(int idx,int x,int y){

    memset(vis[ idx ],-1,sizeof vis[ idx ]);

    queue< pii > q;

    vis[ idx ][ x ][ y ] = 0;

    q.push({x,y});

    while( !q.empty() ){

        pii p = q.front();

        q.pop();

        for(int i = 0; i < 8; i++){

           int x1 = p.ft + X[ i ];
           int y1 = p.sd + Y[ i ];

           if( check(x1,y1) and vis[ idx ][ x1 ][ y1 ] == -1){

                vis[ idx ][ x1 ][ y1 ] = 1 + vis[ idx ][ p.ft ][ p.sd ];

                q.push({x1,y1});
           }
        }
    }
}

int bitmask(int mask,int idx){

    if(mask == len) return vis[ idx ][ v[ 0 ].ft ][ v[ 0 ].sd ];

    if(dp[ mask ][ idx ] != -1) return dp[ mask ][ idx ];

    int ans = 1e9;

    for(int i = 0; i < sz; i++)
    if(!(mask & (1 << i)))ans = min(ans,vis[ idx ][ v[ i ].ft ][ v[ i ].sd ] + bitmask(mask | (1 << i),i));

    return dp[ mask ][ idx ] = ans;
}
int main(){

    file();

    while(scanf("%d %d",&n,&m) == 2){

        v.clear();
        int x = 0,y = 0;

        for(int i = 0; i < n; i++) cin >> s[ i ];

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {

            if(s[ i ][ j ] == '#') v.pb({i,j});
            if(s[ i ][ j ] == 'L') x = i,y = j;
        }

        v.insert(v.begin(),{x,y});

        sz = v.size();

        for(int i = 0; i < sz; i++) bfs(i,v[ i ].ft,v[ i ].sd);

        len = (1 << sz) - 1;

        memset(dp,-1,sizeof dp);

        printf("%d\n",bitmask(0,0));
    }

    return 0;
}
