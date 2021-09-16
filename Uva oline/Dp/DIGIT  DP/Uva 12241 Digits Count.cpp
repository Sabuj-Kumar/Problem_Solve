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

ll a,b;
int sz;
vector< ll > v,cnt;

ll dp[ 12 ][ 2 ];

ll digit_dp(int idx,bool coto,ll count_){

    if(idx == sz) return count_;

    if(dp[ idx ][ coto ] != -1) return dp[ idx ][ coto ];

    int sz1 = coto ? v[ idx ] : 9;
    int ans = 0;

    for(int i = 0; i <= sz1; i++){

        bool fg = true;

        if( i < v[ idx ])  fg = false;

        ans += digit_dp(idx+1,coto | fg,count_+1);
    }

    return dp[ idx ][ coto ] = ans;
}

void convert(ll n){

    memset(dp,-1,sizeof dp);

    v.clear();

    while( n ){

        int mod = n % 10;

        n /= 10;

        v.insert(v.begin(),mod);
    }

    sz = v.size();
}
int main(){

    file();

    while(cin >> a >> b and a and b){


        vector<ll> p,q;

        if( (a - 1) > 1){

            convert(a-1);
            digit_dp(0,1,0);

            p = cnt;

            convert( b );
            digit_dp(0,1,0);

            q = cnt;

            for(int i = 0; i < 10; i++){

                cout << q[ i ] << " ";
            }
            cout << endl;
        }
        else {

            convert(b);
            digit_dp(0,1,0);

            p = cnt;

            for(int i = 0; i < 10; i++) cout << p[ i ] << " ";
            cout << endl;
        }
    }
    return 0;
}
