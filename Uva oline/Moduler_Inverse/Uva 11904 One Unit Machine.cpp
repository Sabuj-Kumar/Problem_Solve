#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define ft first
#define sd second
#define pb push_back
#define pf push_front
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

const int N = 1e6 + 5;
const ll mod = 1000000007;

ll fact[ N ];
ll In_fact[ N ];
ll v[ 1010 ];

int I() { int n; sc( n ); return n; }
ll  Il() { ll n; sl( n ); return n; }

ll big_mod(ll n,ll p){

    ll pw = 1;
    while( p > 0 ){

        if(p & 1) pw = (pw * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return pw;
}

void pre_cal(){

    fact[ 0 ] = In_fact[ 0 ] = 1;

    for(int i = 1; i < N; i++){

        fact[ i ] = (fact[ i - 1 ] * i) % mod;
        In_fact[ i ] = big_mod(fact[ i ],mod - 2);
    }
}

ll nCr(ll n,ll r){

    return (((fact[ n ] * In_fact[ r ]) % mod ) * ((In_fact[ n - r ]) % mod)) % mod;
}
int main(){

    pre_cal();

    file();

    int t = I();

    Case( t ){

        ll n = Il();

        ll total = 0,way = 1;

        for(int i = 0; i < n; i++) v[ i ] = I(),total += v[ i ];

        for(int i = n - 1; i >= 0; i--){

            way = (way * nCr(total - 1,v[ i ] - 1)) % mod;
            total -= v[ i ];
        }

        printf("Case %d: %lld\n",cs,way);
    }
    return 0;
}
