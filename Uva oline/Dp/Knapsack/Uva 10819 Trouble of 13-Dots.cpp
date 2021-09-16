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
#define scl( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
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
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

const int N = 3e4 + 5;
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

int m,n;
int dp[ 150 ][ N ];
vector< pii > ar;

int knapsack(int i,int amount){

    if(m <= 1800 and amount > m) return -90000;

    if(amount > m+200) return -90000;

    if(i == n){

        if(amount > m and amount <= 2000) return -90000;

        return 0;
    }

    if(dp[ i ][ amount ] != -1) return dp[ i ][ amount ];

    int p = 0,q = 0;
    p = ar[ i ].s + knapsack(i+1,amount+ar[ i ].f);
    q = knapsack(i+1,amount);

    return dp[ i ][ amount ] = max(p,q);
}

int main(){

    file();

    while(sc2(m,n) != EOF){

        ar.clear();

        int p = n;
        memset(dp,-1,sizeof dp);

        while( p-- ){

            int a,b;
            sc2(a,b);
            ar.pb({a,b});
        }

        cout << knapsack(0,0) << endl;
    }
    return 0;
}
