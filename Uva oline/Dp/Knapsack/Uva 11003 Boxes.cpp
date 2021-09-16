#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b);
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c);
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

        return a.c > c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll mod){

    if( p == 0) return 1;

    if( !(p % 2) ){

        ll x = big_mod(n,p/2,mod);
        return (x * x) % mod;
    }

    return ( (n % mod) * big_mod(n,p-1,mod)) % mod;
}

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

vector< pii > boxs;
int dp[ 1000 ][ 4000 ];
int n;

int knapsack(int f,int i,int load){

    if(i == n) return 0;

    if(dp[ i ][ load ] != -1) return dp[ i ][ load ];

    int a = 0,b = 0;

    if( !f ) a = 1 + knapsack(1,i+1,boxs[ i ].s);

    else if(load - boxs[ i ].f >= 0) a = 1 + knapsack(f,i+1,min(load - boxs[ i ].f,boxs[ i ].s));

    b = knapsack(f,i+1,load);

    return dp[ i ][ load ] = max(a,b);
}
int main(){

    file();

    int num;

    while( sc( num ) and num){

        n = num;
        int i = 0;
        vector< pii > v( n + 5 );
        swap(v,boxs);

        while( num-- ){

            int w,l;
            sc2(w,l);
            boxs[ i ] = {w,l};
            i++;
        }

        memset(dp,-1,sizeof dp);

        int ans = knapsack(0,0,0);

        cout << ans << endl;
    }
    return 0;
}


