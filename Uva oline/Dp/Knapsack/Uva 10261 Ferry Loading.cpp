#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define scl( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%d %d",&a,&b);
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
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
    data(int x,int y){ this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

const int N = 1e4+10;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

vector< int > len;
int cap,siz;
int dp[ 210 ][ N ];

int knapsack(int i,int amount1,int amount2){

    if(i == siz) return 0;
    if(len[ i ] > amount1 and len[ i ] > amount2) return 0;

    if(dp[ i ][ amount1 ] != -1) return dp[ i ][ amount1 ];

    int p1 = len[ i ] <= amount1 ? knapsack(i+1,amount1 - len[ i ],amount2) + 1 : 0;
    int p2 = len[ i ] <= amount2 ? knapsack(i+1,amount1,amount2 - len[ i ]) + 1 : 0;

    return dp[ i ][ amount1 ] = max(p1,p2);
}

void path(int i,int amount1,int amount2){

    if(i == siz) return;
    if(len[ i ] > amount1 and len[ i ] > amount2) return;

    int p1 = len[ i ] <= amount1 ? knapsack(i+1,amount1 - len[ i ],amount2) + 1 : 0;
    int p2 = len[ i ] <= amount2 ? knapsack(i+1,amount1,amount2 - len[ i ]) + 1 : 0;

    if(p1 > p2) {

        cout << "port" << endl;
        path(i+1,amount1 - len[ i ],amount2);
    }
    else {

        cout << "starboard" << endl;
        path(i+1,amount1,amount2 - len[ i ]);
    }
 }

int main(){

    file();

    int t;

    sc( t );

    while( t-- ){

        int fary,car;

        sc( fary );
        fary *= 100;

        memset(dp,-1,sizeof dp);
        len.clear();

        while( sc( car ) and car) len.pb( car );

        siz = len.size();

        cout << knapsack(0,fary,fary) << endl;
        path(0,fary,fary);

        if( t > 0 ) cout << endl;
    }

    return 0;
}
