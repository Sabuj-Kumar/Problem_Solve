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
#define sl( n ) scanf("%lld",&n)
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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll mod = 1e9 + 7;

const ll N = 28;
ll fact[ 2 * N + 5 ];
vector< ll > catalan(N);
vector< ll > supper_catalan(N);

void fectorial(){

    fact[ 0 ] = fact[ 1 ] = 1;

    for(int i = 2; i < (2 * N); i++) fact[ i ] = (i * fact[ i - 1 ]) % mod;
}

ll big_mod(ll n,ll p){

    ll ans = 1;
    ll a = n;

    while( p ){

        if(p & 1) ans = (ans * n) % mod;

        n = (n * n) % mod;

        p /= 2;
    }

    return ans;
}

void catalan_number(){

    /**
        Super Catalan Number S(n) = ( ( 3*(2 * n - 3) * S[ n - 1 ] ) - ( (n - 1) * S[ n - 2 ] ).
        Catalan Number : C(n ) = ((2 * (2 * n - 1 )) / ( n + 1) ) * C(n - 1 ).
    **/
    supper_catalan[ 0 ] = supper_catalan[ 1 ] = supper_catalan[ 2 ] = 1;

    for(ll i = 3; i < N; i++) supper_catalan[ i ] = ((3 * ( 2 * i - 3) ) * supper_catalan[ i - 1 ]  - (i - 3 ) * supper_catalan[ i - 2 ]) / i;

    catalan[ 0 ] = catalan[ 1 ] = 1,catalan[ 2 ] = 2;

    for(ll i = 3; i < N; i++)catalan[ i ] = catalan[ i - 1 ] * (2 * (2 * i - 1)) / (i + 1);

//    for(int i = 0; i < N; i++) cout << supper_catalan[ i ] << " ";
//    cout << endl;
//
//    for(int i = 0; i < N; i++) cout << catalan[ i ] << " ";
//    cout << endl;
}

int main(){

    catalan_number();

    //file();

    ll n;

    while(cin >> n){

        cout << supper_catalan[ n ] - catalan[ n - 1 ] << endl;
    }

    return 0;
}

