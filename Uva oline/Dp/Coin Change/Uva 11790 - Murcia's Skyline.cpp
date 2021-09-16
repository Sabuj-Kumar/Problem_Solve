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

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ((n % m) * x) % m;
}

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

vector< int > skyline,cost;
int n,mxi,mxd,dp1[ 3005 ],dp2[ 3005 ],lis[ 3005 ],lds[ 3005 ];

int LIS_LDS(int i,int bol){

    if(bol == 1 and dp1[ i ] != -1) return dp1[ i ];
    if(bol == 2 and dp2[ i ] != -1) return dp2[ i ];

    int t,p,ans1 = 0,ans2 = 0;

    lis[ i ] = lds[ i ] = t = p = cost[ i ];
    int f = 0;

    for(int j = 0; j < i; j++){

        if(skyline[ j ] < skyline[ i ]){

            f = 1;
            lis[ i ] = max(lis[ i ],t + lis[ j ]);
            ans1 = max(ans1,LIS_LDS( j,f ));
        }
        else if(skyline[ j ] > skyline[ i ]){

            f = 2;
            lds[ i ] = max(lds[ i ],p + lds[ j ]);
            ans2 = max(ans2,LIS_LDS( j,f));
        }
    }

    mxi = max(lis[ i ],mxi);
    mxd = max(lds[ i ],mxd);
    dp1[ i ] = ans1 + 1;
    dp2[ i ] = ans2 + 1;
    if( f == 1 ) return dp1[ i ];
    else return dp2[ i ];
}

int main(){

    file();

    int t = I();

    Case( t ){

        n = I();

        vector< int > v1( n ),c1( n );
        swap(skyline,v1);
        swap(cost,c1);

        for(int i = 0; i < n; i++) skyline[ i ] = I();
        for(int i = 0; i < n; i++) cost[ i ] = I();

        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);

        mxi = 0,mxd = 0;
        for(int i = 0; i < n; i++) int ans = LIS_LDS( i,0 );

        printf("Case %d. ",cs);

        if(mxi >= mxd) printf("Increasing (%d). Decreasing (%d).\n",mxi,mxd);
        else printf("Decreasing (%d). Increasing (%d).\n",mxd,mxi);
    }

    return 0;
}

