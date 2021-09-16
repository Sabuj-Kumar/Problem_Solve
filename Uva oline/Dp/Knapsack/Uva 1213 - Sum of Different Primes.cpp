#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define pll pair< ll,ll >
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

const int N = 1150 + 5;
const int inf = 1e9;
const ll mxm = 1e18;
const ll mxm_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

struct data{

    int x,y,c;
    data(){}
    data(int x,int y) { this -> x = x,this -> y = y;}
    data(int x,int y,int c) {this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

bool flag[ N ];
vector< int > pm;
ll n,k,dp[ 200 ][ 20 ][ N ];

void seive(){

    memset(flag,true,sizeof flag);

    for(int i = 2; i <= N; i++)
        if(flag[ i ]){

            pm.pb( i );
            for(int j = i * i; j <= N; j += i)
                flag[ j ] = false;
        }
}

ll sc() { ll x; cin >> x; return x; }

ll knapsack(ll i,ll state,ll amount){

   if(state <= 0 or amount <= 0 or pm[ i ] > n){

        if(!state and !amount) return 1;
        return 0;
   }

   if(amount > 0 and !state) return 0;

   if(dp[ i ][ state ][ amount ] != -1) return dp[ i ][ state ][ amount ];

   int p1 = 0,p2 = 0;
   p1 = knapsack(i+1,state -1,amount-pm[ i ]);
   p2 = knapsack(i+1,state,amount);
   return dp[ i ][ state ][ amount ] = p1 + p2;
}
int main(){

    seive();
    op
    file();

    while(cin >> n >> k){

        if(!(n+k)) break;

        if(n == 1) {

            cout << 0 << endl;
            continue;
        }

        memset(dp,-1,sizeof dp);
        ll ans = knapsack(0,k,n);
        cout << ans << endl;
    }
    return 0;
}
