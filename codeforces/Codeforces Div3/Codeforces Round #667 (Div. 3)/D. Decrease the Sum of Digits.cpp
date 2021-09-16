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

ll sum(ll n){

    ll jog = 0;

    while( n ) { jog += (n % 10); n /= 10; }

    return jog;
}
ll solve(ll n,ll s){

    ll nw = 1,ans = 0;

    while(sum( n ) > s){

        if(n % 10 == 0) nw *= 10,n /= 10;
        else ++n,ans += nw;
    }
    return ans;
}
int main(){

    op;
    file();

    int t;
    cin >> t;

    while( t-- ){

        ll n,s;
        cin >> n >> s;

        ll ans = solve(n,s);

        cout << ans << endl;
    }
    return 0;
}

