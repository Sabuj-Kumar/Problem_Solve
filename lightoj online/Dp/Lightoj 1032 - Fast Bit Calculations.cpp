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

ll n,sz;
ll dp[ 34 ][ 2 ][ 2 ][ 34 ];
vector<int> v;

void convert(ll n){

    v.clear();

    while( n ){

        int mod = n % 2;
        n /= 2;
        v.insert(v.begin(),mod);
    }

    sz = v.size();

    memset(dp,-1,sizeof dp);
}
ll digit_dp(int idx,int pre,bool flag,int cnt){

    if(idx == sz) return cnt;

    if(dp[ idx ][ pre ][ flag ][ cnt ] != -1) return dp[ idx ][ pre ][ flag ][ cnt ];

    int mx = 1;
    ll add = 0;

    if(!flag) mx = v[ idx ];

    for(int i = 0; i <= mx; i++){

        bool fg;

        if(i < v[ idx ]) fg = 1;
        else fg = 0;

        add += digit_dp(idx + 1,i,flag | fg,(pre == 1 and i == 1) + cnt);
    }

    return dp[ idx ][ pre ][ flag ][ cnt ] = add;
}
int main(){

    op
    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> n;

        convert( n );

        cout << "Case " << cs << ": "<< digit_dp(0,0,0,0) << endl;
    }
    return 0;
}
