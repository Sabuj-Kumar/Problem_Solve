#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pci pair< char ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
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

    bool operator < (const data &a) const{

        return c > a.c;
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

    if( !( p % 2 ) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int I() {int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }

string s[ 30 ];
int n,cn;

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < n;
}

void dfs(int x,int y){

    if(s[ x ][ y ] == '0') return;

    cn++;

    s[ x ][ y ] = '0';

    for(int i = 0; i < 8; i++){

        int a = x + X[ i ];
        int b = y + Y[ i ];

        if(check(a,b)) dfs(a,b);
    }
}
int main(){

    file();
    int t = I();

    cin.ignore();
    cin.ignore();

    Case( t ){

        n = 0;

        while( getline(cin,s[ n ]) ){

            if(s[ n ].size()==0) break;

            n++;
        }

        int mxi = 0;

        lop(i,0,n){

            lop(j,0,n){

                if(s[ i ][ j ] == '1' ){

                    cn = 0;

                    dfs(i,j);

                    if(cn > mxi) mxi = cn;
                }
            }
        }

        cout << mxi << endl;

        if( cs < t  )cout << endl;
    }

    return 0;
}


