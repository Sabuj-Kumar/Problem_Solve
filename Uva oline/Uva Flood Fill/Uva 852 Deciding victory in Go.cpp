#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db dobule
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_back
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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

    bool operator < (const data &a) const {

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

ll big_mod(ll n,ll p){

    if( !p ) return 1;

    if( !( p % 2 ) ){

        ll x = big_mod(n,p/2);
        return (x * x) % mod;
    }

    ll x = big_mod(n,p-1);
    return ( (n % mod) * x) % mod;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }
char s[ 15 ][ 15 ];
int flag[ 15 ][ 15 ],wt,bl,cn;
bool blk,wth;

bool okay(int x,int y){

    return x >= 0 and x < 9 and y >= 0 and y < 9;
}

void dfs(int x,int y){

    if(s[ x ][ y ] == '.'){

        s[ x ][ y ] = '*';
        cn++;
    }
    else {

        if(s[ x ][ y ] == 'O') wth = true;
        else if(s[ x ][ y ] == 'X') blk = true;
        return;
    }
    for(int i = 0; i < 4; i++){

        int a = x + X[ i ];
        int b = y + Y[ i ];

        if(okay(a,b)) dfs(a,b);
    }
}
int main(){

    file();

    int t = I();

    while( t-- ){

        bl = wt = 0;

        lop(i,0,9){

           cin >> s[ i ];

           lop(j,0,9){

                if(s[ i ][ j ] == 'O') wt++;
                else if(s[ i ][ j ] == 'X') bl++;
           }
        }

        lop(i,0,9)
        lop(j,0,9){

            if(s[ i ][ j ] == '.'){

                blk = wth = false;
                cn = 0;
                dfs(i,j);
                if(blk and wth) continue;
                if(blk) bl += cn;
                else wt += cn;
            }
        }

        cout << "Black " << bl <<  " White " << wt << endl;
    }

    return 0;
}
