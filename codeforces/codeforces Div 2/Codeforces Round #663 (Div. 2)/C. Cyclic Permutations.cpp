#include<bits/stdc++.h>
#define ll long long
#define db double
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

ll fact[ 10000009 ];
ll mod = 1e9 + 7;

int I() {int n; scanf("%d",&n); return n; }
ll Il() { ll n; scanf("%I64d",&n); return n; }

ll big_mod(ll v,ll p){

    if( !p ) return 1;
    if(p == 1) return (v % mod);

    if(p & 1) return (big_mod(v,p-1) * v) % mod;

    ll x = big_mod(v,p/2) % mod;
    return (x * x) % mod;
}

ll inverse(ll v){

    return big_mod(v,mod-2);
}
int main(){

    file();

    ll n = Il();

    fact[ 0 ] = 1;

    for(ll i = 1; i <= n; i++){

        fact[ i ] = fact[ i - 1 ] * (i % mod);
        fact[ i ] %= mod;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){

        ll c = (fact[ n - 1 ] * inverse( (fact[ i ] % mod) * (fact[ n - i - 1] % mod) % mod ) % mod) % mod;
        ans += c;

        ans %= mod;
    }
    printf("%I64d\n",(fact[ n ] - ans + mod) % mod);

    return 0;
}
