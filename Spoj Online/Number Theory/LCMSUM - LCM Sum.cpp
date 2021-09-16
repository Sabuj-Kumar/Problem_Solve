#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long long
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

const int N = 1000005;
ll phi[ N ];
ll res[ N ];

void phi_cal(){

    /**
        GCD_SUM = sum( [ divisor's_of_n * phi[ n / divisor's_of_n ] ] )
        LCM_SUM = (n / 2) * ( sum( [ divisor's_of_n * phi[ divisor's_of_n ] ] ) + 1 )
    **/
    phi[ 0 ] = 0;
    phi[ 1 ] = 1;

    for(ll i = 2; i <= N; i++) phi[ i ] = i - 1;

    for(ll i = 2; i < N; i++)
        for(ll j = i + i; j < N; j += i)
            phi[ j ] -= phi[ i ];

    for(ll i = 1; i <= N; i++)
        for(ll j = i; j <= N; j += i)
            res[ j ] += (i * phi[ i ]);
}
int main(){

    phi_cal();

    //file();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        cout << (n * (res[ n ] + 1) ) / 2 << endl;
    }
    return 0;
}
