#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define lli long long int
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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}
lli mod = 1000000007;
int cnt[ 5000 ];
lli dp[ 1010 ][ 8192 ];
lli v[ 1010 ];
int sz = 0;
bool flag[ 9000 ];
int m = 8192;

void count_(){

  for(int i = 2; i <= 8192; i++ )
    if(!flag[ i ])
     for(int j = 2; i * j <= 8192; j++)
       flag[ i * j ] = true;
}

lli solve(int idx,int xr) {

    if(idx == sz && xr == 0) return 1;
    if(idx == sz) return 0;
    if(dp[ idx ][ xr ] != -1) return dp[ idx ][ xr ];

    int val = v[ idx ];
    int evn = cnt[ val ] / 2;
    int odd = cnt[ val ] / 2;

    if(cnt[ val ] % 2 == 1) odd++;
    evn++;

    int xrr = xr xor val;

    return dp[ idx ][ xr ] = (((ll)(solve(idx + 1,xrr) * odd)) % mod + (((ll)(solve(idx + 1,xr) * evn))%mod))%mod;
 }

int main()
{
    count_();

    op

    file();

    int t;
    cin >> t;

    while(t--){

        memset(cnt,0,sizeof cnt);
        memset(dp,-1,sizeof dp);
        sz = 0;
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){

            int a;

            cin >> a;

            if(cnt[ a ] == 0) v[ sz++ ] = a;

            cnt[ a ]++;
        }

        lli ans = 0;

        for(int i = 2; i <= m; i++)
        if(!flag[ i ] ) ans = (ans + solve(0,i)) % mod;

        cout << ans << endl;
    }

    return 0;
}
