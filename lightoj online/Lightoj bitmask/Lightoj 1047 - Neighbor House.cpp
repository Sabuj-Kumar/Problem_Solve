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
#define sl( n ) scanf("%d",&n)
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

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;
bool prime[ N + 5 ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

struct data{

    int x,y,c;

    data() {}
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
void seive(){

    memset(prime,true,sizeof prime);
    prime[ 0 ] = prime[ 1 ] = false;

    for(int i = 2; i < N; i++)
        if(prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = false;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n;
int ar[ 1001 ][ 4 ],dp[ 1001 ][ 4 ];

int min_cost_path_dp(int i,int j){

    if(i == n) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    int ans = inf;

    for(int k = 0; k < 3; k++)
        if(k != j) ans = min(ans,ar[ i ][ j ] + min_cost_path_dp(i + 1,k));

    return dp[ i ][ j ] = ans;
}

int main(){

    file();

    int t = I();

    Case( t ){

        memset(dp,-1,sizeof dp);

        n = I();

        lop(i,0,n)
        lop(j,0,3)
        ar[ i ][ j ] = I();

        int ans = inf;

        for(int i = 0; i < 3; i++) ans = min(ans,min_cost_path_dp(0,i));
        printf("Case %d: %d\n",cs,ans);

        ///okay
    }

    return 0;
}

