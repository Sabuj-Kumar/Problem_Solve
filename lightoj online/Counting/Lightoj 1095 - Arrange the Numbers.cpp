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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll  Il() { ll n; sl( n ); return n; }


const ll mod = 1000000007;
const int N = 1e3 + 10;
ll fact[ N ];
ll dp[ N ][ N ];

void pre(){

    fact[ 0 ] = 1;

    for(int i = 1; i <= N; i++) fact[ i ] = (i * fact[ i - 1 ]) % mod;

    memset(dp,-1,sizeof dp);
}

ll nCr(ll n,ll r){

    if(n == r) return 1;
    if(r == 1) return n;

    if(dp[ n ][ r ] != -1) return dp[ n ][ r ];

    return dp[ n ][ r ] = ((nCr(n-1,r-1)) % mod + (nCr(n-1,r)) % mod) % mod;
}
int main(){

    pre();

    file();

    int t;

    cin >> t;

    Case( t ){

        ll n,m,k;

        cin >> n >> m >> k;

        ll ans = nCr(m,k);

        ll nn = (n - k);

        ll ans1 = fact[ n - k ];

        for(int i = 1; i <= (m - k); i++){

            if(i % 2) ans1 -= (nCr(m - k,i) * fact[ nn - i ]) % mod;
            else ans1 += (nCr(m - k,i) * fact[ nn - i ]) % mod;

            ans1 = (ans1 + mod) % mod;
        }

        cout << "Case " << cs << ": " << (ans * ans1) % mod << endl;
    }
    return 0;
}
