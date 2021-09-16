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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator <(const data &a) const {

        return a.c > c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

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
    return ( (n % m) * x ) % m;
}

int I() { int n; sc( n ); return n; }
ll Il() {  ll n; sl( n ); return n; }

int sum,p,q,n,ar[ 15 ][ 15 ],vis[ 15 ][ 15 ];

bool check(int x,int y){

    return x >= p and x <= q and y >= p and y <= q;
}
void dfs_r1(int x,int y){

    if(vis[ x ][ y ] != -1) return;

    vis[ x ][ y ] = 1;

    int y1 = y + 1;

    if(check(x,y1)){

        sum += ar[ x ][ y ];
        dfs_r1(x,y1);
    }
}
void dfs_r2(int x,int y){

    if(vis[ x ][ y ] != -1) return;

    vis[ x ][ y ] = 1;

    int y1 = y + 1;

    if(check(x,y1)){

        sum += ar[ x ][ y ];
        dfs_r2(x,y1);
    }
}
void dfs_d1(int x,int y){

    if(vis[ x ][ y ] != -1) return;

    vis[ x ][ y ] = 1;

    int x1 = x + 1;

    if(check(x,x1)){

        sum += ar[ x ][ y ];
        dfs_d1(x1,y);
    }
}
void dfs_d2(int x,int y){

    if(vis[ x ][ y ] != -1) return;

    vis[ x ][ y ] = 1;

    int x1 = x + 1;

    if(check(x1,y)){

        sum += ar[ x ][ y ];
        dfs_d2(x1,y);
    }
}
int main(){

    file();
    int cs = 0;

    while( sc( n ) and n){

        lop(i,0,n)
        lop(j,0,n)
        sc( ar[ i ][ j ] );

        vector< int > v;

        memset(vis,-1,sizeof vis);

        for(int i = 0; i < n - i; i++){

            sum = 0;

            p = i;
            q = n - i;

            dfs_r1(i,i);
            dfs_r2(n-i-1,i);
            dfs_d1(i+1,i);
            dfs_d2(i+1,n-i-1);

            v.pb( sum );
        }

        cout << "Case " << ++cs << ": ";

        for(int i = 0; i < v.size(); i++) {

            cout << v[ i ];

            if(i < v.size()-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
