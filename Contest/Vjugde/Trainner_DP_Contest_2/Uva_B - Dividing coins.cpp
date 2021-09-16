#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scl( n ) scanf("%lld",&n)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

ll big(ll n,ll p,ll mod){

    if( !p ) return 1;

    ll x = 0;

    if( !(p % 2 ) ){

        x = big(n,p/2,mod);
        return (x * x) % mod;
    }

    x = big(n,p-1,mod);

    return ((n % mod) * x) % mod;
}

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,-2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

vector< int > vec;
int n,cap,dp[ 110 ][ 50000 ];

int knapsack(int i,int amount){

    if(i == n) return 0;

    if(dp[ i ][ amount ] != -1) return dp[ i ][ amount ];

    int p = 0,q = 0;

    if(amount + vec[ i ] <= cap) p = vec[ i ] + knapsack(i+1,amount + vec[ i ]);

    q = knapsack(i + 1,amount);

    return dp[ i ][ amount ] = max(p,q);
}
int main(){

    file();
    int test;

    sc( test );

    Case( test ){

        int a,sum = 0;
        sc( n );

        vector< int > v( n + 5 );
        swap(vec,v);

        lop(i,0,n){

            sc( a  );
            vec[ i ] = a;
            sum += vec[ i ];
        }

        cap = sum / 2;

        memset(dp,-1,sizeof dp);

        printf("%d\n",sum - 2 * knapsack(0,0));
    }

    return 0;
}
