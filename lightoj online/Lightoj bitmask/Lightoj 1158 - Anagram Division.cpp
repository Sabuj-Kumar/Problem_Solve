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
#define sl( n ) scanf("%lld",&n);
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

char s[ 12 ];
int d,n,sz,a[ 12 ];
ll dp[ 1005 ][ 1 << 10 ];

ll bit_mask(int val,ll mask){

    if(mask == n) return val == 0;

    if(dp[ val ][ mask ] != -1) return dp[ val ][ mask ];

    ll ans = 0;
    bool vis[ 12 ];

    memset(vis,false,sizeof vis);

    for(int i = 0; i < sz; i++)
        if( !vis[ a[ i ] ] and !(mask & (1 << i)) ){

            vis[ a[ i ] ] = true;
            ans += bit_mask((10 * val + a[ i ]) % d,mask | (1 << i));
        }

    return dp[ val ][ mask ] = ans;
}
int main(){

    file();

    int t;

    scanf("%d",&t);

    Case( t ){

        memset(dp,-1,sizeof dp);

        scanf("%s",s);
        scanf("%d",&d);

        sz = strlen(s);

        for(int i = 0; i < sz; i++) a[ i ] = s[ i ] - 48;

        n = (1 << sz) - 1;

        ll num = bit_mask(0,0);

        printf("Case %d: %lld\n",cs,num);
    }
    return 0;
}
