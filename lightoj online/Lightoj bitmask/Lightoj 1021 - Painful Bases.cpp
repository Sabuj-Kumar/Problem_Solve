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
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = 0; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
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

    bool operator <( const data &a) const {

        return c > a.c;
    }
};

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

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int I(){ int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }

int Set(int mask,int p) { return mask = mask | 1 << p; }
int reset(int mask,int p) { return mask =  mask & ~(1 << p); }
bool check(int mask,int p) { return  mask & (1 << p); }

int base,k,a[ 25 ],n,len;
ll dp[ 1 << 17 ][ 25 ];

ll bitmask(int mask,int number){

    if(mask == n){

        if( !number ) return 1;
        return 0;
    }

    if(dp[ mask ][ number ] != -1) return dp[ mask ][ number ];

    ll res = 0;

    for(int i = 0; i < len; i++)
        if(!check(mask,i))
            res += bitmask(Set(mask,i),(base * number + a[ i ]) % k);

    return dp[ mask ][ number ] = res;
}

int main(){

    file();

    int t = I();

    Case( t ){

        base = I(),k = I();
        string s;
        cin >> s;
        len = s.length();

        n = (1 << len) - 1;

        memset(a,0,sizeof a);

        for(int i = 0; i < len; i++){

            if(s[ i ] >= '0' and s[ i ] <= '9') a[ i ] = s[ i ] - '0';
            else a[ i ] = s[ i ] - 'A' + 10;
        }

        memset(dp,-1,sizeof dp);

        printf("Case %d: %lld\n",cs,bitmask(0,0));
    }
    return 0;
}
