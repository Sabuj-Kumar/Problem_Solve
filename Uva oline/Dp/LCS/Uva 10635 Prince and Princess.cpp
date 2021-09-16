#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll >
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
    return ( (n % m) * x) % m;
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

int n,a,b;
int m[ 62510 ];

vector< int > p,q;

int LIS( ){

    int lis = 0,sz = p.size();

    for(int i = 0; i < sz; i++){

        int id = lower_bound(q.begin(),q.end(),p[ i ]) - q.begin();

        q[ id ] = p[ i ];

        lis = max(lis,id);
    }
    return lis;
}
int main(){

    file();
    int t = I();

    Case( t ){

        p.clear();
        q.clear();

        memset(m,0,sizeof m);
        q.pb( -inf );
        p.pb( 0 );

        n = I();
        a = I();
        b = I();

        lop(i,0,a + 1) { int x = I(); m[ x ] = i; }

        lop(i,0,b + 1) { int x = I(); if( m[ x ] ) p.pb( m[ x ] ),q.pb( inf ); }

       // q.pb( inf );

        printf("Case %d: %d\n",cs,LIS( ));
    }
    return 0;
}
