#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll >
#define pb push_back
#define pf push_front
#define f first
#define s second
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

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if(!(p % 2)){

        ll x = big(n,p/2,m);
        return (x * x);
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x);
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

int I() {int n; sc( n ); return n; }
ll Il() {ll  n; sl( n ); return n; }

int lns,lnp;
int a[ 120 ],b[ 120],dp[ 1005 ][ 1005 ];

int LCS(int i,int j){

    if(i == lns or j == lnp) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    int ans = 0;

    if(a[ i ] == b[ j ]) ans = 1 + LCS(i+1,j+1);
    else {

        int v1 = LCS(i + 1,j);
        int v2 = LCS(i,j + 1);
        ans = max(v1,v2);
    }
    return dp[ i ][ j ] = ans;
}
int main(){

    file();

    int css = 0;
    bool f = false;
    while(cin >> lns >> lnp and lns or lnp){

        memset(dp,-1,sizeof dp);

        lop(i,0,lns) cin >> a[ i ];
        lop(i,0,lnp) cin >> b[ i ];

        printf("Twin Towers #%d\n",++css);
        printf("Number of Tiles : %d\n\n",LCS(0,0));
    }
    return 0;
}
