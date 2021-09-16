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

const int N = 1e7+20;
vector< ll > prime;
ll mb[ N ];
bool vis[ N ];

void seive(){

    int rt = sqrt(N);

    for(ll i = 2; i <= rt+1; i++)
        if(!vis[ i ])
            for(ll j = i + i; j < N; j += i) vis[ j ] = 1;

    for(ll i = 2; i < N; i++) if(!vis[ i ]) prime.pb( i );
}

void mobius(){

    for(int i = 1; i < N; i++) mb[ i ] = 1;
    int rt = sqrt(N);

    for(int i = 0; i < prime.size() and prime[ i ] <= rt; i++){

        ll x = prime[ i ] * prime[ i ];

        for(ll j = x; j < N; j += x) mb[ j ] = 0;
    }

    for(int i = 0; i < prime.size(); i++)
        for(ll j = prime[ i ]; j < N; j += prime[ i ])
            mb[ j ] *= -1;
}
int main(){

    op;
    seive();
    mobius();

    //file();

    int t;

    cin >> t;

    while(t--){

        ll n;

        cin >> n;

        int sq = sqrt( n );

        ll ans = 0;

        for(ll i = 1; i <= sq; i++){

            ll x = i;

            ans += mb[ i ] * (n / (x * x));
        }
        cout << ans << endl;
    }

    return 0;
}
