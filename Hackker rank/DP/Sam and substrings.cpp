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

string s;
int mod = 1e9 + 7;

void sum(){

    int n = s.size();

    vector< ll > b( n );
    b[ 0 ] = 1;

    for(int i = 1; i < n; i++) b[ i ] = (b[ i - 1 ] * 10 + 1) % mod;

    ll ans = 0;

    for(int i = 0; i < n; i++){

        ///s[ i ] * sum( i = (0 to n - 1)) 10^i * (i + 1); (this is the digit sum formula)
        ans += (((s[ i ] - '0')) * b[ n - i - 1 ] * (i + 1)) % mod;

        ans %= mod;
    }

    cout << ans << endl;
}
int main(){

    //file();

    cin >> s;

    sum();

    return 0;
}
