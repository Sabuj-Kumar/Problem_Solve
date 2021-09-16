#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
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

ll a,b,k,sz;
ll dp[ 12 ][ 2 ][ 100 ][ 100 ];
vector< ll > v;

ll digit_dp(ll idx,bool flag,ll dig,ll num){

    if(idx == sz) return !(dig + num) ? 1 : 0;

    if(dp[ idx ][ flag ][ dig ][ num ] != -1) return dp[ idx ][ flag ][ dig ][ num ];

    ll ln = 9,sum = 0;

    if(flag) ln = v[ idx ];

    for(ll i = 0; i <= ln; i++){

        bool flg;

        if(i < v[ idx ]) flg = 0;
        else flg = flag;

        sum += digit_dp(idx + 1,flg,((dig + i) % k),((num * 10 + i) % k));
    }
    return dp[ idx ][ flag ][ dig ][ num ] = sum;
}

void convert(ll n){

    v.clear();

    while( n ){

        ll p = n % 10;
        n /= 10;
        v.insert(v.begin(),p);
    }

    sz = v.size();

    memset(dp,-1,sizeof dp);
}
int main(){

    file();

    int t = I();

    Case( t ){

        sl( a );
        sl( b );
        sl( k );

        cout << "Case " << cs << ": ";

        if(k > 82){

            cout << "0" << endl;
            continue;
        }
        else if(k == 1) cout << b - a + 1 << endl;
        else{

            convert( a - 1 );
            ll ans_a = digit_dp(0,1,0,0);
            convert( b );
            ll ans_b = digit_dp(0,1,0,0);

            cout << ans_b - ans_a << endl;
        }
    }
    return 0;
}
