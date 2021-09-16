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

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

string s,out;
int dp[ 1005 ][ 1005 ];

int LCS(int i,int j){

    if(i > j) return 0;

    if(i == j) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == s[ j ]) return dp[ i ][ j ] = LCS(i + 1,j - 1);

    return dp[ i ][ j ] = min(LCS(i + 1,j),LCS(i,j-1)) + 1;
}

void path(int i,int j){

    if( i > j ) return;

    if(s[ i ] == s[ j ]){

        out += s[ i ];
        path(i + 1,j - 1);
        if(i != j) out += s[ j ];
    }
    else if(LCS(i,j) == LCS(i + 1,j) + 1){

        out += s[ i ];
        path(i + 1,j);
        out += s[ i ];
    }
    else if(LCS(i,j) == LCS(i,j - 1) + 1){

        out += s[ j ];
        path(i,j - 1);
        out += s[ j ];
    }
}
int main(){

    file();

    while(getline(cin,s)){

        memset(dp,-1,sizeof dp);

        out = "";

        int lcs = LCS(0,s.size()-1);
        path(0,s.size() - 1);

        cout << lcs << " " << out << endl;
    }

    return 0;
}


