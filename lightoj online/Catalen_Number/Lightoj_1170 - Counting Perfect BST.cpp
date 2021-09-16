#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll mod = 100000007;
const int N = 1e6 + 10;
ll sz = 10000000000;
ll ft[ N ];
set< ll > s;
vector< ll > v;

void fact(){

    ft[ 0 ] = 1;

    for(int i = 1; i <= N; i++)

        ft[ i ] = ((ft[ i - 1 ] % mod)  * (i % mod )) % mod;
}

ll inv(int n,int p){

    if(p == 1) return n % mod;
    if(p == 0) return 1;

    if(!(p & 1)) {

        ll x = inv(n,p/2) % mod;

        return ((x % mod) * (x % mod)) % mod;
    }

    ll x = inv(n,p-1) % mod;
    return (x * n) % mod;
}

void power(){

    ll mul;

    for(ll i = 2; i*i <= sz; i++){

        mul = i;

        while(mul <= sz){

            mul *= i;

            if(!s.count(mul)){

                s.insert(mul);
                v.pb(mul);
            }
        }
    }

    sort(v.begin(),v.end());
}

ll catalan(ll n){

    if(n == 0) return 0;

    ll x = ft[ 2 * n ];
    ll y = ft[ n ];
    ll z = ft[ n + 1 ];

    ll p = inv( (y*z) % mod,mod-2) % mod;

    return ((x % mod) * (p % mod))% mod;
}
int main(){

    //file();
    fact();
    power();

    int n;

    cin >> n;

    Case( n ){

        ll a,b;

        cin >> a >> b;

        ll x = upper_bound(v.begin(),v.end(),a-1) - v.begin();
        ll y = upper_bound(v.begin(),v.end(),b) - v.begin();

        ll num = y - x;

        ll ans = catalan( num );

        cout << "Case "<< cs << ": " << ans << endl;
    }

    return 0;
}

