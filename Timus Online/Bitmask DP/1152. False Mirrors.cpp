#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = 0; i < n; i++)
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
    data(int x,int y,int c){ this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

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

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int I() { int n; sc( n ); return n; }
int Il() { ll n; sl( n ); return n; }

int n,lim,a[ 25 ],dp[ 1 << 21 ];

int bit_mask(int mask){

    if(mask == lim) return 0;

    if(dp[ mask ] != -1) return dp[ mask ];

    int ans = inf;

    for(int i = 0; i < n; i++)
    if( !(mask & (1 << i)) ){

        int temp = mask;

        temp |= (1 << i);
        temp |= (i - 1) < 0 ? (1 << (n - 1)) : (1 << (i - 1));
        temp |= (i + 1) == n ? (1 << 0) : (1 << (i + 1));

        int count_ = 0;

        for(int j = 0; j < n; j++) if(!(temp & (1 << j))) count_ += a[ j ];

        ans = min(ans,count_+bit_mask(temp));
    }
    return dp[ mask ] = ans;
}

int main(){

    file();

    n = I();

    lop(i,0,n) a[ i ] = I();
    memset(dp,-1,sizeof dp);
    lim = (1 << n) - 1;
    //cout << lim << endl;
    cout << bit_mask( 0 ) << endl;

    return 0;
}
