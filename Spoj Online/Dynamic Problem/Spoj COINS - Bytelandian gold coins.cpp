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

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

ll n;
map<ll,ll > dp;

ll knapsack(ll amt){

    if( amt <= 2) return amt;

    if(dp.count( amt )) return dp[ amt ];

    return dp[ amt ] = max(amt,knapsack(amt/2) + knapsack(amt/3) + knapsack(amt/4));
}
int main(){

    file();

    while(scanf("%lld",&n) != EOF) printf("%lld\n",knapsack( n ));

    return 0;
}
