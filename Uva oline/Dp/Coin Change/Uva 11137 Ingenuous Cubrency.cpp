#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

ll n,dp[ 25 ][ 10005 ];
ll coin[ 25 ];

ll coin_change(int idx,ll amt){

    if(amt == 0) return 1;

    if(amt < 0 or idx == 22) return 0;

    if(dp[ idx ][ amt ] != -1) return dp[ idx ][ amt ];

    return dp[ idx ][ amt ] = coin_change(idx,amt-coin[ idx ]) + coin_change(idx + 1,amt);
}
int main(){

    for(int i = 1; i <= 21; i++) coin[ i ] = i*i*i;
    memset(dp,-1,sizeof dp);
    file();

    while(cin >> n) cout << coin_change(1,n) << endl;

    return 0;
}
