#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define ft first
#define sd second
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

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
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
const ll mod = 1e9 + 7;

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int x,y,a,b,n;
vector< pii > v;
int dp[ 15 ][ 1 << 12 ],cost[ 15 ][ 15 ];

int dis(pii a,pii b){

    int x = abs(a.ft - b.ft);
    int y = abs(a.sd - b.sd);
    return x + y;
}

int bit_mask(int idx,int mask){

    if(mask == (1 << n) - 1) return cost[ 0 ][ idx ];

    if(dp[ idx ][ mask ] != -1) return dp[ idx ][ mask ];

    int ans = inf;

    for(int i = 0; i < n; i++){

        if( mask & (1 << i) ) continue;

        ans = min(ans,cost[ idx ][ i ] + bit_mask(i,mask | (1 << i)));
    }
    return dp[ idx ][ mask ] = ans;
}
int main(){

    file();

    int t = I();

    while( t-- ){

        v.clear();

        x = I(),y = I();

        v.pb( {I(),I()} );

        n = I();
        n++;

        memset(cost,0,sizeof cost);
        memset(dp,-1,sizeof dp);

        for(int i = 1; i < n; i++) v.pb({I(),I()});

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                cost[ i ][ j ] = cost[ j ][ i ] = dis(v[ i ],v[ j ]);

        cout << "The shortest path has length " << bit_mask(0,0) << endl;
    }

    return 0;
}

