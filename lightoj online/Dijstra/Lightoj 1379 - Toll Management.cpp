#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pii pair< int,int >
#define pll pair<ll,ll>
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define sc3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define scl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    ll x,c;

    data() {}
    data(int x) { this -> x = x; }
    data(int x,int c) { this -> x = x,this -> c = c; }

    bool operator < (const data &a) const{

        return a.c > c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}


ll big_mod(ll n,ll p,ll mod){

    if(p == 0) return 1;

    ll x;

    if( !(n % p) ){

        x = big_mod(n,p/2,mod);
        return (x * x) % mod;
    }

    x = big_mod(n,p-1,mod);

    return ((n%mod) * x)% mod;
}

const int N = 2 * 1e5;
const ll inf = 1e9 + 7;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

vector< vector< data > > graph1,graph2;
ll n,m,s,t,d,a,b,tk;
ll dis1[ N ],dis2[ N ];

void dij2(ll s){

    priority_queue< data > Q;

    Q.push(data(s,0));
    dis2[ s ] = 0;

    while( !Q.empty() ){

        data p = Q.top();
        Q.pop();

        for(auto a : graph2[ p.x ]){

            if(dis2[ a.x ] > a.c + dis2[ p.x ]){

                dis2[ a.x ] = a.c + dis2[ p.x ];
                Q.push(data(a.x,dis2[ a.x ]));
            }
        }
    }
}
void dij1(ll s){

    priority_queue< data > Q;
    Q.push(data(s,0));
    dis1[ s ] = 0;

    while( !Q.empty() ){

        data p = Q.top();
        Q.pop();

        for(auto a : graph1[ p.x ]){

            if(dis1[ a.x ] > a.c + dis1[ p.x ]){

                dis1[ a.x ] = a.c + dis1[ p.x ];

                Q.push(data(a.x,dis1[ a.x ]));
            }
        }
    }
}
int main(){

    file();

    int test;

    sc( test );

    Case( test ){

        sc2(n,m);
        sc3(s,t,d);
        //cout << n << " " << m << " " << s << "  " << t << "  " << d << endl;
        vector< vector< data > > v( n + 5 ),v1(n + 5);
        swap(graph1,v);
        swap(graph2,v1);

        while( m-- ){

            sc3(a,b,tk);
            //cout << a << " " << b << " " << tk << endl;
            graph1[ a ].pb(data(b,tk));
            graph2[ b ].pb(data(a,tk));
        }

        Lop(i,1,n+5) dis1[ i ] = inf,dis2[ i ] = inf;

        dij1( s );
        dij2( t );
        ll ans = -1;

        for(ll p = 1; p <= n; p++){

            for(auto a : graph1[ p ]){

                if(dis1[ p ] + dis2[ a.x ] + a.c <= d) ans = max(ans,a.c);
            }
        }
        cout << "Case " << cs << ": " << ans << endl;
    }

    return 0;
}
