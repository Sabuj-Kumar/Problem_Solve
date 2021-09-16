#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x ) * m;
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N =  1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int I() { int n; sc( n ); return n; }
ll Il() { ll n; sl( n );  return n; }

int n,m,ans;
vector< vector< int > > graph;
bool used[ 30 ][ 30 ];

void back_track(int node,int path = 0){

    bool flag = true;

    for(auto x : graph[ node ]){

        if(!used[ node ][ x ]){

            flag = false;

            used[ node ][ x ] = true;
            used[ x ][ node ] = true;

            back_track(x,path+1);

            used[ node ][ x ] = false;
            used[ x ][ node ] = false;
        }
    }

    if(flag) ans = max(ans,path);
}
int main(){

    file();

    while(cin >> n >> m and n and m){

        vector< vector< int > > v( n + 5 );
        swap(graph,v);

        for(int i = 0; i < m; i++) {

            int a,b;
            cin >> a >> b;
            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        ans = -1;

        for(int i = 0; i < n; i++) back_track( i );

        cout << ans << endl;
    }

    return 0;
}
