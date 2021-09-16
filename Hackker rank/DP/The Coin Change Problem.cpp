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
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n)for(int i = v; i < n; i++)
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

int n,m;
vector< int > v;
ll dp[ 60 ][ 500 ];

ll coin_change(int idx,int val){

    if(idx == m) {

        if(val == n) return 1;
        return 0;
    }

    if(val == n) return 1;

    if(dp[ idx ][ val ] != -1) return dp[ idx ][ val ];

    ll p = 0,q = 0;

    if(val <= n) p = coin_change(idx,val + v[ idx ]);

    q = coin_change(idx + 1,val);

    return dp[ idx ][ val ] = p + q;
}
int main(){

    //file();

    cin >> n >> m;

    for(int i = 0; i < m; i++){

        ll a;
        cin >> a;
        v.pb( a );
    }

    memset(dp,-1,sizeof dp);

    cout << coin_change(0,0) << endl;

    return 0;
}
