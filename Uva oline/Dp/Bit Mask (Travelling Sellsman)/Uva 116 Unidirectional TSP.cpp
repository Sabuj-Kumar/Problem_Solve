#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define ft first
#define sd second
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdin(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

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

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;
bool prime[ 100010 ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x ) % m;
}

void siv(){

    memset(prime,true,sizeof prime);

    for(int i = 2; i < N; i++)
        if(prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = false;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,m;
int matrix[ 15 ][ 110 ],dp[ 15 ][ 1 << 20 ],path[ 15 ][ 110 ];

int bit_mask(int idx,int mask){

    if(idx == n or mask == (1 << m) - 1) return matrix[ 0 ][ idx ];

    if(dp[ idx ][ mask ] != -1) return dp[ idx ][ mask ];

    int ans = inf;

    for(int i = 0; i < m; i++)
        if( !(mask & (1 << i)) )
            ans = min(ans,matrix[ idx ][ i ] + bit_mask(idx + 1,mask | (1 << i)));

    return dp[ idx ][ mask ] = ans;
}
int main(){

    file();

    while(cin >> n >> m){

        cout << n << " " << m << endl;
        lop(i,0,n)
        lop(j,0,m)
        matrix[ i ][ j ] = I();

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++) cout << matrix[ i ][ j ] << " ";
            cout << endl;
        }

        cout << endl;

        memset(dp,-1,sizeof dp);
        memset(path,0,sizeof path);

        int ans = inf,st = 0;

        for(int i = 0; i < n; i++) {

            int a = bit_mask(i,0);

            if(ans >= a){

                ans = a;
                st = i;
            }
        }

        cout << ans << endl << endl;
    }

    return 0;
}
