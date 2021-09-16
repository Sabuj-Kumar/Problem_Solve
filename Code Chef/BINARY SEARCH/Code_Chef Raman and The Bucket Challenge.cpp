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
db Id() { db n; sdl( n ); return n; }

ll n;

ll sum(ll v){

    return (v * (v + 1)) / 2;
}
ll Binary_search(){

    ll l = 1,r = 1e9,mid = 0;

    while(r - l > 1){

        mid = l + (r - l) / 2;

        if(sum( mid ) >= n) r = mid;
        else l = mid;
    }
    return r;
}
int main(){

    file();

    int t = I();

    while( t-- ){

        cin >> n;

        cout << Binary_search( ) << endl;
    }
    return 0;
}



