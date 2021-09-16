#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int main(){

    file();
    int t;
    int M = 100000007;

    scanf("%d",&t);

    Case( t ){

        int n,tk;

        scanf("%d",&n);
        scanf("%d",&tk);

        int coin[ n ];
        int dp[ tk + 1 ] = {0};

        for(int i = 0; i < n; i++) scanf("%d",&coin[ i ]);

        dp[ 0 ] = 1;

        for(int i = 0; i < n; i++)
        for(int j = 1; j <= tk; j++)
        if(j >= coin[ i ]) dp[ j ] += dp[ j - coin[ i ] ],dp[ j ] %= M;

        printf("Case %d: %d\n",cs,dp[ tk ]);
    }

    return 0;
}
