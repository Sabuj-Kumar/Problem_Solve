#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pii pair< int ,int >
#define pll pair< ll , ll >
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sc2( a,b ) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&a,&c)
#define scl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
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
    data(int x,int c) { this -> x = x,this -> c = c; }
    data(int x,int y,int c) { this -> x = x,this ->  y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return a.c > c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll mod){

    if( !p ) return 1;
    ll x = 0;

    if( !(p % 2) ){

        x = big_mod(n,p/2,mod);
        return (x * x) % mod;
    }
    x = big_mod(n,p-1,mod);
    return ( (n % mod) * x ) % mod;
}

int main(){

    //file();

    db n;
    cin >> n;
    db sum = 0;

    Lop(i,0,n){

        db a;
        cin >> a;
        sum += a;
    }
    cout << fixed << setprecision(12);
    cout << sum / n << endl;

    return 0;
}

