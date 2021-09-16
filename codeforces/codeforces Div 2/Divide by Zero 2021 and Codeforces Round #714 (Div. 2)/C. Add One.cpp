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
#define in freopen("in.txt","r",stdin);

using  namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 2*1e5 + 10;

int dp[ N ];
int mod = 1e9+7;

void solve(){

    int n,m,ans = 0;

    cin >> n >> m;

    while(n > 0){

        int x = n % 10;

        ans += (x + m < 10) ? 1 : dp[ m + x - 10 ];
        ans %= mod;
        n /= 10;
    }

    cout << ans << endl;
}
int main(){

    op;
    for(int i = 0; i < 9; i++) dp[ i ] = 2;
    dp[ 9 ] = 3;

    for(int i = 10; i < N; i++) dp[ i ] = (dp[ i - 9 ] + dp[ i - 10 ]) % mod;

    file();

    int t;

    cin >> t;

    while(t--){

        solve();
    }

    return 0;
}

