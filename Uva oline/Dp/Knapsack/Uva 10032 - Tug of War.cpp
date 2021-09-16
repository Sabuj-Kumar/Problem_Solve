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
#define Case( n ) for(int cs = 1; cs <= cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int INF = 1e9;

int n,sum;
int a[ 110 ];
int dp[ 55 ][ 25010 ];

int knapsack(int idx,int cnt,int w){

    if( cnt > (n + 1) / 2) return INF;

    if(idx == n){

        if(abs(cnt - (n - cnt)) <= 1) return abs(w - (sum - w));

        return INF;
    }

    if(dp[ cnt ][ w ] != -1) return dp[ cnt ][ w ];

    int r = INF;

    r = min(r,knapsack(idx + 1,cnt + 1,w + a[ idx ]));
    r = min(r,knapsack(idx + 1,cnt,w));

    return dp[ cnt ][ w ] = r;
}
int main(){

    file();

    int t;
    bool f = false;

    sc( t );

    while( t-- ){

        memset(dp,-1,sizeof dp);
        sum = 0;

        if( f ) puts("");
        f = true;

        sc( n );

        lop(i,0,n) {

            sc(a[ i ]);

            sum += a[ i ];
        }

        int diffirence = (knapsack(0,0,0));

        int ans1 = (sum + diffirence) / 2;
        int ans2 = sum - ans1;

        if(ans1 > ans2) swap(ans1,ans2);

        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
