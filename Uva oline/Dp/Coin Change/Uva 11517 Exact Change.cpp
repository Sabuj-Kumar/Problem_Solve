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

int n,p,coin[ 105 ],dp[ 105 ][ 10005 ],dp1[ 105 ][ 10005 ];

int tk(int idx,int amount){

    if(amount >= p) return amount;
    if(idx >= n) return inf;

    if(dp[ idx ][ amount ]) return dp[ idx ][ amount ];

    return dp[ idx ][ amount ] = min(tk(idx+1,amount),tk(idx+1,amount + coin[ idx ]));
}
int num_of_coin(int idx,int amt){

    if(amt == 0) return 0;
    if(amt < 0 or idx >= n) return inf;

    if(dp1[ idx ][ amt ]) return dp1[ idx ][ amt ];

    return dp1[ idx ][ amt ] = min(num_of_coin(idx+1,amt),num_of_coin(idx+1,amt - coin[ idx ]) + 1);
}
int main(){

    file();

    int t;

    sc( t );

    while( t-- ){

        memset(dp,0,sizeof dp);
        memset(dp1,0,sizeof dp1);
        sc( p );
        sc( n );

        lop(i,0,n) sc( coin[ i ] );

        int cost = tk(0,0);
        printf("%d %d\n",cost,num_of_coin(0,cost));
    }
    return 0;
}
