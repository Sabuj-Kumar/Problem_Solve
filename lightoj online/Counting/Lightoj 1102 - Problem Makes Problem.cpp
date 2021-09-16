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

const int N = 2 * 1e6 + 10;
const ll mod = 1000000007;
ll fact[ N ];

void init(){

    fact[ 0 ] = 1;

    for(int i = 1; i < N; i++) fact[ i ] = (fact[ i - 1 ] * i) % mod;
}

ll big_mod(ll n,ll m){

    ll ans = 1;

    while( m ){

        if(m & 1) ans = (ans * n) % mod;

        n = (n * n) % mod;

        m /= 2;
    }

    return ans;
}
int main(){

    init();

    file();

    int t;

    cin >> t;

    Case( t ){

        int n,k;

        cin >> n >> k;

        ll down = big_mod((fact[ n ] * fact[ k - 1 ]) % mod,mod-2) % mod;

        cout << "Case " << cs << ": "<< (fact[ n + k - 1 ] * down) % mod << endl;
    }
    return 0;
}
