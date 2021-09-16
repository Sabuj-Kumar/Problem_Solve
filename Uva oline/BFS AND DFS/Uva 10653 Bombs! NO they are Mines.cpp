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
    data() {}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll mod){

    if( !p ) return 1;

    ll x = 0;

    if( !(p % 2) ){

        x = big_mod(n,p/2,mod);
        return ( x * x ) % mod;
    }
    x = big_mod(n,p-1,mod);
    return ((n % mod) * x) % mod;
}

vector< vector< int > > grid;
int vis[ 1010 ][ 1010 ];
int r,c;

bool check(int x,int y){

    return x >= 0 and x < r and y >= 0 and y < c and grid[ x ][ y ] != -1 and vis[ x ][ y ] == -1;
}
void BFS(int a,int b,int c,int d){

    queue< pii > Q;
    Q.push({a,b});
    vis[ a ][ b ] = 0;

    while( !Q.empty() ){

        pii p = Q.front();
        Q.pop();

        if(p.f == c and p.s == d) return;

        for(int i = 0; i < 4; i++){

            int x = p.f + X[ i ];
            int y = p.s + Y[ i ];

            if( check(x,y) ){

                Q.push({x,y});
                vis[ x ][ y ] = vis[ p.f ][ p.s ] + 1;
            }
        }
    }
}
int main(){

    file();

    while( scanf("%d %d",&r,&c) and r and c ){

        int n;
        vector< vector< int > > v(r,vector< int > (c,0));
        swap(grid,v);

        scanf("%d",&n);

        while(n--){

            int a,b,m;

            scanf("%d %d",&a,&m);

            while(m--){

                scanf("%d",&b);

                grid[ a ][ b ] = -1;
            }
        }

        int a,b,c,d;

        scanf("%d %d",&a,&b);
        scanf("%d %d",&c,&d);

        memset(vis,-1,sizeof vis);

        BFS(a,b,c,d);

        printf("%d\n",vis[ c ][ d ]);
    }

    return 0;
}
