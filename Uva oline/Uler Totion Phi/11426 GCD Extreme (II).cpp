#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = 0; i < n; i++)
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

const int N = 1000005;
ll phi[ N ] = {0};
ll phi_cal[ N ] = {0};

void phi_func(){

    /**
        GCD_SUM = sum( [ divisor's_of_n * phi[ n / divisor's_of_n ] ] )
        LCM_SUM = (n / 2) * ( sum( [ divisor's_of_n * phi[ divisor's_of_n ] ] ) + 1 )
    **/
    phi[ 0 ] = 0;
    phi[ 1 ] = 1;

    for(ll i = 2; i < N; i++) phi[ i ] = i - 1;

    for(ll i = 2; i < N; i++)
        for(ll j = i + i; j < N; j += i)
            phi[ j ] -= phi[ i ];

    for(int i = 1; i < N; i++)
        for(int j = i + i; j < N; j += i)
            phi_cal[ j ] += (i * phi[ j / i ]);

    for(int i = 2; i < N; i++) phi_cal[ i ] += phi_cal[ i - 1 ];
}

int main(){

    phi_func();
    op;
    //file();

    ll n;

    while(cin >> n){

        if(n == 0) break;

        cout << phi_cal[ n ] << endl;
    }



    return 0;
}
