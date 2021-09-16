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
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define pb push_back
#define pf push_front
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

int n;
double dp[ 150 ];
vector< int > v;

double Ex_value(int idx){

    if(idx == n) return v[ n ];

    if(dp[ idx ] != -1.0) return dp[ idx ];

    double p = (double)v[ idx ];

    int sz = min(6,n-idx);

    for(int i = 1; i <= sz; i++) p += (1.0/sz) * Ex_value(idx + i);

    return dp[ idx ] = p;
}
int main(){

    op
    file();

    int t;

    cin >> t;

    Case( t ){

        for(int i = 0; i < 150; i++)  dp[ i ] = -1.0;

        cin >> n;
        v.resize(n+6,0);

        for(int i = 1; i <= n; i++){

            int a;

            cin >> a;

            v[ i ] = a;
        }

        double ans = Ex_value( 1 );

        cout << fixed << setprecision( 10 );
        cout << "Case " << cs << ": " << ans << endl;
    }

    return 0;
}
