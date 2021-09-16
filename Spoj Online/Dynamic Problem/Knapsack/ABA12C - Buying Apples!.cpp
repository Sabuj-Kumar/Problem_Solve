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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int sz,dp[ 105 ][ 1005][ 1005 ];
vector< int > v,pk;

int coin_change(int idx,int kg,int cst){

    if(kg <= 0){

        if(kg == 0) return cst;

        return INT_MAX;
    }

    if(idx == sz) return INT_MAX;

    if(dp[ idx ][ kg ][ cst ] != -1) return INT_MAX;

    int p = coin_change(idx,kg-pk[ idx ],cst+v[ idx ]);
    int q = coin_change(idx + 1,kg,cst);

    return dp[ idx ][ kg ][ cst ] = min(p,q);
}
int main(){

    file();

    int t = I();

    while(t--){

        v.clear();
        pk.clear();

        memset(dp,-1,sizeof dp);

        int n = I(),k = I();

        for(int i = 0; i < k; i++){

            int a = I();

            if( a != -1) {

                v.pb( a );
                pk.pb( i + 1 );
            }
        }

        sz = v.size();
//        for(int i = 0; i < sz; i++) cout << v[ i ] << " ";
//        cout << endl;
        int ans = coin_change(0,k,0);

        if(ans == INT_MAX) cout << -1 << endl;

        else cout << ans << endl;
    }

    return 0;
}
