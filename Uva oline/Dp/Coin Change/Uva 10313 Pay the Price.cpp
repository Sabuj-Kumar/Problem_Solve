#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define pf push_front
#define f first
#define s second
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
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

    bool operator <(const data &a) const {

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
const ll mxx  = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int I() { int n; sc( n ); return n; }
ll Il() { ll n;  sl( n ); return n; }

string s;
ll sz,n;
ll dp1[ 305 ][ 305 ];
ll dp2[ 305 ][ 305 ][ 305 ];
ll dp3[ 305 ][ 305 ][ 305 ];
bool flag;

ll coin_cng1(int idx,ll amt){

    if(amt < 0) return 0;

    if(idx == 0){

        if(amt == 0) return 1;
        return 0;
    }

    if(dp1[ idx ][ amt ] != -1) return dp1[ idx ][ amt ];

    return dp1[ idx ][ amt ] = coin_cng1(idx,amt - idx) + coin_cng1(idx - 1,amt);
}

ll coin_cng2(ll idx,ll amt,ll coin){

    if(coin < 0 or amt < 0) return 0;

    if(idx == 0){

        if(amt == 0){

            if( flag ) return 1;
            if(coin == 0) return 1;
        }
        return 0;
    }

    if( flag and dp2[ idx ][ amt ][ coin ] != -1 ) return dp2[ idx ][ amt ][ coin ];
    if( !flag and dp3[ idx ][ amt ][ coin ] != -1) return dp3[ idx ][ amt ][ coin ];

    ll t = coin_cng2(idx,amt - idx,coin - 1) + coin_cng2(idx - 1,amt,coin);

    if( flag ) return dp2[ idx ][ amt ][ coin ] = t;
    if( !flag ) return dp3[ idx ][ amt ][ coin ] = t;
}
int main(){

    file();
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    memset(dp3,-1,sizeof dp3);

    while(getline(cin,s)){

        stringstream ss( s );
        ll x;
        ll a[ 5 ];
        n = 0;
        while( ss >> x ) a[ n++ ] = x;

        ll ans = 0;

        if(n == 1)ans = coin_cng1(a[ 0 ],a[ 0 ]);
        else if(n == 2){

            a[ 1 ] = min(a[ 0 ],a[ 1 ]);
            flag = true;
            ans = coin_cng2(a[ 0 ],a[ 0 ],a[ 1 ]);
        }
        else {

            a[ 2 ] = min(a[ 0 ],a[ 2 ]);
            flag = false;

            for(int x = a[ 1 ]; x <= a[ 2 ]; x++)
                ans += coin_cng2(a[ 0 ],a[ 0 ],x);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
