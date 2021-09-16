#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pii pair< int,int>
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define Lop(i,v,n) for(int i = v; i < n; i++)
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

const int N = 1e5+5;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int sc() { int v; scanf("%d",&v); return v; }
ll sl() { ll v; scanf("%lld",&v); return v; }

int coin[ 8 ],coin_number[ 8 ],q,u;
int dp[ 8 ][ N ];

int coin_change(int i,int amount){

    if(i == 4 || amount == 0 ){

        if( !amount ) return 1;

        return 0;
    }

    if(dp[ i ][ amount ] != -1) return dp[ i ][ amount ];

    int p1 = 0,p2 = 0;

    if(u - coin[ i ] >= 0 ) p1 = coin_change(i,amount - coin[ i ]);

    p2 = coin_change(i+1,amount);

    return dp[ i ][ amount ] = p1 + p2;
}
int main(){

    file();

    int test = sc();

    while( test-- ){

        Lop(i,0,4)coin[ i ] = sc();
        q = sc();

        while( q-- ){

            Lop(i,0,4) coin_number[ i ] = sc();
            u = sc();

            memset(dp,-1,sizeof dp);

            printf("%d\n",coin_change( 0,u ));
        }
    }

    return 0;
}
