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

int main(){

    file();

    vector< ll > v;

    v.pb(3);
    v.pb(11);
    v.pb(101);
    v.pb(1009);
    v.pb(10007);
    v.pb(100003);
    v.pb(1000003);
    v.pb(10000019);
    v.pb(100000007);

    int t;

    cin >> t;

    while(t--){

        ll a,b,c;

        cin >> a >> b >> c;

        ll x = v[ c - 1 ];
        ll y = v[ c - 1 ];

        ll p = log10( x ) + 1;
        ll q = log10( y ) + 1;

        while(a != p){

            x *= 2;

            p = log10( x ) + 1;
        }

        while(b != q){

            y *= 3;

            q = log10( y ) + 1;
        }

        cout << x << " " << y << endl;
    }
    return 0;
}

