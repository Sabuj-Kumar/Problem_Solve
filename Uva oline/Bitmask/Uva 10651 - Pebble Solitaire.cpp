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
#define f first
#define s second
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
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
const int mxi = (1 << 12) - 1;
int I(){ int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }

int dp[ 1 << 12 + 5 ];

int bitmask(int mask){

    if(dp[ mask ] != -1) return dp[ mask ];

    dp[ mask ] = inf;

    bool chk = true;

    for(int i = 0; i < 10; i++){

        if((mask & (1 << i)) and (mask & (1 << (i + 1))) and !(mask & (1 << (i + 2)))){

            int x = mask;
            x ^= (1 << i);
            x ^= (1 << (i + 1));
            x |= (1 << (i + 2));

            dp[ mask ] = min(dp[ mask ],bitmask( x ));

            chk = false;
        }
        if(!(mask & (1 << i)) and (mask & (1 << (i + 1))) and (mask & (1 << (i + 2)))){

            int x = mask;
            x |= 1 << i;
            x ^= (1 << (i + 1));
            x ^= (1 << (i + 2));

            dp[ mask ] = min(dp[ mask ],bitmask( x ));

            chk = false;
        }
    }

    if( chk ){

        dp[ mask ] = 0;

        lop(i,0,12) if(mask & (1 << i)) dp[ mask ]++;
    }
    return dp[ mask ];
}

int main(){

    file();
    memset(dp,-1,sizeof dp);
    int T = I();

    while( T-- ){

        string s;

        cin>> s;

        int mask = 0;

        lop(i,0,s.size())
            if(s[ i ] == 'o')
                mask |= 1 << i;

        cout << bitmask( mask ) << endl;
    }
    return 0;
}
