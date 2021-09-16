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

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

int I(){ int n; sc( n ); return n; }
int Il() { ll n; sl( n ); return n; }

ll coin[ ] = {1,5,10,25,50};
ll n,dp[ 6 ][ 30000 + 50 ];

ll coin_change(ll idx,ll amount){

    if(amount > n) return 0;

    if(idx == 5) {

        if(amount == n) return 1;

        return 0;
    }

    if(dp[ idx ][ amount ] != -1) return dp[ idx ][ amount ];

    return dp[ idx ][ amount ] = coin_change(idx,amount+coin[ idx ]) + coin_change(idx+1,amount);
}
int main(){

    file();

    while( cin >> n ){

        memset(dp,-1,sizeof dp);
        ll ans = coin_change( 0,0 );

        if( ans == 1 ) cout << "There is only "<< 1 << " way to produce " << n << " cents change.";
        else cout << "There are "<< ans << " ways to produce " << n << " cents change.";
        cout << endl;
    }

    return 0;
}
