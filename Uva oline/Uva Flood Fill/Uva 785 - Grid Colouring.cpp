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
#define sc( n ) scanf("%d",&n);
#define sl( n ) scanf("lld",&n);
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
int hy[ ] = {-1,1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p){

    if( !p ) return 1;
    ll x = 0;
    if( !(p % 2) ){

        x = big_mod(n,p/2);
        return (x * x) % mod;
    }
    x = big_mod(n,p-1);
    return ( (n % mod) * x) % mod;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }

string s[ 40 ];

int vis[ 40 ][ 100 ];

void dfs(int i,int j,char ch){

    if(vis[ i ][ j ] or s[ i ][ j ] == 'X') return;

    s[ i ][ j ] = ch;
    vis[ i ][ j ] = 1;

    for(int id = 0; id < 4; id++){

        int x = i + X[ id ];
        int y = j + Y[ id ];

        dfs(x,y,ch);
    }
}
int main(){

    file();

    while( 1 ){

        int n = 0;
        for(int i = 0; i < 40; i++) s[ i ].clear();

        while( 1 ){

            if(!getline(cin,s[ n ])) return 0;

            if(s[ n ][ 0 ] == '_') break;

            n++;
        }

        memset(vis,0,sizeof vis);

        for(int i = 0; i < n-1; i++)
            for(int j = 0; j < s[ i ].size(); j++)
                if(s[ i ][ j ] != 'X' and s[ i ][ j ] != ' ' and !vis[ i ][ j ])
                    dfs(i,j,s[ i ][ j ]);

        for(int i = 0; i < n; i++)
            cout << s[ i ] << endl;

        puts("_____________________________");
    }

    return 0;
}
