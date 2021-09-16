#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll >
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

const int sz = 1e6+50;
ll dp[ 110 ][ sz ];
ll w[ 110 ],cost[ 110 ];
ll N,W;

ll Knapsack(int idx,ll wt){

    if(idx == N) return 0;

    if(dp[ idx ][ wt ] != -1) return dp[ idx ][ wt ];

    ll p = 0,q = 0;

    if( (wt + w[ idx ]) <= W ) p = Knapsack(idx+1,wt+w[ idx ]) + cost[ idx ];

    q = Knapsack(idx+1,wt);

    return dp[ idx ][ wt ] = max(p,q);
}
int main(){

    memset(dp,-1,sizeof dp);

    file();

    cin >> N >> W;

    for(int i = 0; i < N; i++) cin >> w[ i ] >> cost[ i ];

    cout << Knapsack(0,0) << endl;

    return 0;
}
