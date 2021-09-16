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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct Data{

    int x,y,c;

    Data() {}
    Data(int x) { this -> x = x; }
    Data(int x,int y) { this -> x = x,this -> y = y; }
    Data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const Data &a) const{

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

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2)){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    return (((n % m) * big(n,p-1,m)) % m);
}

ll gcd(ll a,ll b){

    if(b == 0) return a;
    return gcd(b,a%b);
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,m;
string s,p,out;
int dp[ 110 ][ 110 ];

int lcs(int i,int j){

    if(i == n or j == m) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == p[ j ]) return dp[ i ][ j ] = 1 + lcs(i + 1,j + 1);

    return dp[ i ][ j ] = max(lcs(i,j + 1),lcs(i + 1,j));
}

void print_path(int i,int j){

    if(i >= n) { for(;j < m; j++) out += p[ j ]; return; }
    if(j >= m) { for(;i < n; i++) out += s[ i ]; return; }

    int a = lcs(i + 1,j);
    int b = lcs(i,j + 1);

    if(s[ i ] == p[ j ]){

        out += s[ i ];
        print_path(i + 1,j + 1);
    }
    else if(a >= b) {

        out += s[ i ];
        print_path(i + 1,j);
    }
    else {

        out += p[ j ];
        print_path(i,j + 1);
    }
}
int main(){

    file();

    while(cin >> s >> p){

        n = s.size();
        m = p.size();
        out = "";

        memset(dp,-1,sizeof dp);

        lcs(0,0);
        print_path(0,0);

        cout << out << endl;
    }

    return 0;
}
