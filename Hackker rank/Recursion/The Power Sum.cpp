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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll n,x,rang;
ll dp[ 50 ][ 2000 ];

ll Sum(ll idx,ll sum){

    if(idx == rang or sum > x){

        if(sum == x) return 1;
        return 0;
    }

    if(sum == x) return 1;

    if(dp[ idx ][ sum ] != -1) return dp[ idx ][ sum ];

    ll p = 0,q = 0;

    p = Sum(idx+1,sum+pow(idx,n));

    q = Sum(idx+1,sum);

    return dp[ idx ][ sum ] = p + q;
}
int main(){

    //file();

    memset(dp,-1,sizeof dp);

    cin >> x >> n;

    rang = sqrt( x )+1;

    ll ans = Sum(1,0);

    cout << ans << endl;

    return 0;
}
