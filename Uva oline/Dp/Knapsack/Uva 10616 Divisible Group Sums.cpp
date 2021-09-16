#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll, ll >
#define f first
#define s second
#define pb push_back
#define pf push__front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
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
    data(int x,int y) { this -> x = x,this -> y = y ; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

const int N = 1e5;
const int inf = 1e9;
const ll mxx = 1e18;
const ll mxx_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int sc() { int n; scanf("%d",&n); return n; }
int n,q,d,m;
int ar[ 210 ];
int dp[ 210 ][ 15 ][ 50 ];

int knapsack(int i,int state,int amount){

    if(!state and !amount) return 1;
    if(i == n or !state and amount) return 0;

    if(dp[ i ][ state ][ amount ] != -1) return dp[ i ][ state ][ amount ];

    int p1 = knapsack( i+1,state-1,((amount+ar[ i ]) % d) );
    int p2 = knapsack( i+1,state,(amount % d) );

    return dp[ i ][ state ][ amount ] = p1 + p2;
}
int main(){

    file();

    int s = 0;

    while( cin >> n >> q and n and q ){

        Lop(i,0,n) ar[ i ] = sc();

        printf("SET %d:\n",++s);

        Lop(j,1,q+1){

            memset(dp,-1,sizeof dp);

            d = sc(),m = sc();

            printf("QUERY %d: %d\n",j,knapsack(0,m,0));
        }
    }
    return 0;
}
