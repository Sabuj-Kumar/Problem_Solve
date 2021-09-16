#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scan("%d",&n)
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
///ll nCr(int n,int r){
///
///    if(r == 1) return n;
///    if(n == r) return 1;
///
///    if(nr[ n ][ r ] != -1) return nr[ n ][ r ];
///
///    return nr[ n ][ r ] = nCr(n-1,r)+nCr(n-1,r-1);
///}

const ll mod = 1e9 + 7;
const ll N = 1e5+5;

ll fact[ N + 10 ];
ll in_fact[ N + 10 ];

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

    fact[ 0 ] = in_fact[ 0 ] = 1;

    for(int i = 1; i < N; i++){

        fact[ i ] = (fact[ i - 1 ] * i) % mod;
        in_fact[ i ] = big_mod(fact[ i ],mod - 2) % mod;
    }
}

ll nCr(ll n,ll r){

    return (((fact[ n ] * in_fact[ r ]) % mod ) * (in_fact[ n - r ]) % mod ) % mod;
}
int main(){

    op;
    //pre_cal();

    //file();

    ll n,k,x;

    cin >> n >> k >> x;

    ll a[ n ],b[ n ];

    a[ 0 ] = x == 1 ? 1 : 0;
    b[ 0 ] = x == 1 ? 0 : 1;

    for(int i = 1; i < n; i++){

        a[ i ] = b[ i - 1 ] % mod;
        b[ i ] = ((a[ i - 1 ] * ( k - 1 )) % mod + (b[ i - 1 ] * (k - 2)) % mod) % mod;
    }

    cout << a[ n - 1 ] << endl;

    return 0;
}
