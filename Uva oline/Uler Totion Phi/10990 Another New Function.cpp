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

const int N = 2 * 1e6 + 10;
int phi[ N ];
ll depth_phi[ N ];

ll cal(ll n){

    ll temp = n;
    int cnt = 0;

    while(temp != 1){

        temp = phi[ temp ];

        cnt++;
    }

    return cnt;
}
void phi_cal(){

    phi[ 0 ] = 0;
    phi[ 1 ] = 1;

    for(int i = 2; i < N; i++) phi[ i ] = i - 1;

    for(int i = 2; i < N; i++)
        for(int j = i + i; j < N; j += i)
            phi[ j ] -= phi[ i ];

    memset(depth_phi,-1,sizeof depth_phi);

    for(ll i = 2; i < N; i++) depth_phi[ i ] = cal( i );
}
int main(){

    phi_cal();

   // file();

    int t;

    cin >> t;

    while(t--){

        ll sum = 0,a,b;

        cin >> a >> b;

        for(int i = a; i <= b; i++) sum += depth_phi[ i ];

        cout << sum << endl;
    }

    return 0;
}
