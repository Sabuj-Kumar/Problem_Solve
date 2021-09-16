#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%ld",&n)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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

int n,w,k;
int dp[ 110 ][ 110 ];
int x,y[ 110 ];

int knapsack(int idx,int mov){

    if(idx >= n or mov >= k) return 0;

    if(dp[ idx ][ mov ] != -1) return dp[ idx ][ mov ];

    int i,cnt = 0;

    for(i = 0; i + idx < n; i++){

        if(y[ idx ] + w < y[ idx + i ]) break;

        cnt++;
    }

    int p = cnt + knapsack(idx + i,mov + 1);

    int q = knapsack(idx + 1,mov);

    return dp[ idx ][ mov ] = max(p,q);
}

int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        memset(dp,-1,sizeof dp);

        cin >> n >> w >> k;

        for(int i = 0; i < n; i++) cin >> x >> y[ i ];

        sort(y,y+n);

        cout << "Case " << cs << ": " << knapsack(0,0) << endl;
    }

    return 0;
}
