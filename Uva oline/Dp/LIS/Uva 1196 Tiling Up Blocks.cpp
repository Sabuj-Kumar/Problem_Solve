#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define f first
#define s second
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

vector< pair< int,int> > v;
int dp[ 10005 ];
int n;

int LIS(int i){

    if(dp[ i ] != -1) return dp[ i ];

    int ans = 0;

    for(int j = 0; j < i; j++) if(v[ j ].s <= v[ i ].s) ans = max(ans,LIS( j ));

    return dp[ i ] = ans + 1;
}

int main(){

    file();

    while(cin >> n and n){

        v.clear();
        for(int i = 0; i < n; i++) {

            int a,b;
            scanf("%d %d",&a,&b);
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(),v.end());
        memset(dp,-1,sizeof dp);
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans,LIS( i ));

        printf("%d\n",ans);
    }

    printf("*\n");

    return 0;
}


