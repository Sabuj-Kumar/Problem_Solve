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
#define p_b push_back
#define p_f push_front
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define Case( n ) for(int cs = 1; cs <= n; cs++)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){};
    data(int x,int y) { this-> x = x,this -> y = y; }
    data(int x,int y,int cost) { this -> x = x,this -> y = y,this -> cost = cost; }

    bool operator < (const data &a) const {

        return cost > a.cost;
    }
};

ll gcd(ll a,ll b){

    if(b == 0) return a;
    return gcd(b,a%b);
}

int X[ ] = {0,01,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int Hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int Hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int sz = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mx_ = -1e18;
const int mod = 100000007;

int sc() { int n; cin >> n; return n; }
vector< int > c,a;
int cn,amt;
int dp[ 55 ][ 25 ][ 1010 ];

int coin(int i,int state,int amount){

    if(i == cn){
        if(amount == 0) return 1;
        return 0;
    }

    if(dp[ i ][ state ][ amount ] != -1) return dp[ i ][ state ][ amount ];

    int r1 = 0,r2 = 0;
    if(amount - c[ i ] >= 0 and state < a[ i ]) r1 = coin(i,state + 1,amount - c[ i ]);
    else r1 = 0;
    r2 = coin(i+1,0,amount);

    return dp[ i ][ state ][ amount ] = (r1 + r2) % mod;
}
int main(){

    op;
    file();

    int t = sc();

    Case( t ){

        cn = sc();
        amt = sc();
        vector< int > v( cn + 5 ),v1( cn + 5 );
        swap(c,v);
        swap(a,v1);
        lop(0,cn) c[ i ] = sc();
        lop(0,cn) a[ i ] = sc();
        memset(dp,-1,sizeof dp);

        int ans = coin(0,0,amt);

        cout << "Case "<< cs << ": " << ans << endl;
    }

    return 0;
}
