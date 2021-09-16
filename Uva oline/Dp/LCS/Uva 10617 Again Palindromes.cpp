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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;
bool prime[ 100000 ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

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

ll big(ll n,ll p,ll m){

   if( !p ) return 1;

   if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
   }
   ll x = big(n,p-1,m);
   return ( (n % m) * x ) % m;
}

void sieve(){

    memset(prime,false,sizeof prime);

    for(int i = 2; i < N; i++)
        if(!prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = true;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

string s;
ll dp[ 80 ][ 80 ];

ll LCS(int i,int j){

    if(i > j) return 0;
    if(i == j) return 1;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == s[ j ]) return dp[ i ][ j ] = 1 + LCS(i + 1,j) + LCS(i,j - 1);
    else return dp[ i ][ j ] = LCS(i + 1,j) + LCS(i,j - 1) - LCS(i + 1,j - 1);
}
int main(){

    file();

    int t = I();
    cin.ignore();

    while( t-- ){

        getline(cin,s);

        memset(dp,-1,sizeof dp);

        cout << LCS(0,s.size() - 1) << endl;
    }

    return 0;
}
