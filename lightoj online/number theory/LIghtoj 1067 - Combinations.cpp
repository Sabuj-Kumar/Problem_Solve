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
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sl( n )scanf("%lld",&n)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}
const int N = 1e6 + 5;
const ll mod = 1000003;
ll fact[ N ];
ll In_fact[ N ];

int I() { int n; sc( n );  return n; }
ll Il() { ll  n; sl( n ); return n; }

ll big_mod(ll n,ll p){

    ll ans = 1;

    while( p > 0 ){

        if(p & 1) ans = (ans * n) % mod;

        n = (n * n) % mod;

        p /= 2;
    }

    return ans;
}

void pre_cal(){

    fact[ 0 ] = In_fact[ 0 ] = 1;

    for(ll i = 1; i < N; i++){

        fact[ i ] = (fact[ i - 1 ] * i) % mod;
        In_fact[ i ] = (big_mod(fact[ i ],mod - 2)) % mod;
    }
}

ll nCr(ll n,ll r){

    return (((fact[ n ] * In_fact[ r ]) % mod ) * (In_fact[ n - r ]) % mod ) % mod;
}
int main(){

    pre_cal();

    file();

    int t = I();

    Case( t ){

        ll a = Il();
        ll b = Il();

        ll ans = nCr(a,b);

        cout << "Case " << cs << ": " << ans << endl;
    }

    return 0;
}
