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

const ll N = 5010;
ll fact[ 2 * N + 5 ];
vector< ll > catalan(N);

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

void power(){

    catalan[ 0 ] = catalan[ 1 ] = 1;

    for(ll i = 2; i < N; i++){

        catalan[ i ] = 0;

        for(ll j = 0; j < i; j++){

            catalan[ i ] += (catalan[ j ] * catalan[ i - j - 1 ]) % mod;
            catalan[ i ] %= mod;
        }
    }
}
ll catalan_number(ll n){

    return catalan[ n ];
}
int main(){

    power();

    //file();

    ll n,t;

    cin >> n;

    while(n--){

        cin >> t;

        cout << catalan_number( t ) << endl;
    }

    return 0;
}
