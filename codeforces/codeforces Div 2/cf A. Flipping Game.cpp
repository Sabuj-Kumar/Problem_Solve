#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("input.txt","r",stdin)

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

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    return ( (n % m) * big(n,p-1,m) ) % mod;
}

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    int n = I();
    int sum = 0;

    int v[ n + 5 ] = {0};

    lop(i,1,n+1) {

        v[ i ] = I(),sum += v[ i ];
        v[ i ] += v[ i - 1 ];
    }

    int mxi = 0;

    for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j++){

        int ones = v[ j ] - v[ i - 1 ];
        int zeros = (j - i + 1) - ones;
        mxi = max(mxi,zeros - ones);
    }

    if(sum == n) cout << sum - 1 << endl;
    else cout << sum + mxi << endl;

    return 0;
}
