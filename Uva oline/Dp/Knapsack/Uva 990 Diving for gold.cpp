#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define fl float
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("input.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

ll gcd(ll a,ll b){

    if(b == 0) return a;
    return gcd(b,a%b);
}

struct data{

    int x,y,cost;
    data() {}
    data(int x,int y) { this-> x = x,this-> y = y; }
    data(int x,int y,int cost) { this-> x = x,this-> y =y,this->cost = cost; }

    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

const int sz = 1e4;
const int inf = 1e9;
const ll mx = 1e18;
const ll inf_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int Hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int Hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int sc() { int n; cin >> n; return n; }

vector < int > cost,tim,vec,path;
int n,cap,w;
int dp[ 32 ][ sz + 5 ];

void knapsackpath(int i,int T){

    if(i == n) return;

    if(dp[ i ][ T ] != dp[ i + 1 ][ T ]){

        path.p_b(  i  );
        knapsackpath(i + 1,T + vec[ i ]);
    }
    else knapsackpath(i + 1,T);
}
int knapsack(int i,int T){

    if(i == n) return 0;

    if(dp[ i ][  T ] != -1) return dp[ i ][ T ];

    int r1 = 0,r2 = 0;

    if(T + vec[ i ] <= cap) r1 = cost[ i ] + knapsack(i+1,T+vec[ i ]);
    else r1 = 0;

    r2 = knapsack(i+1,T);

    return dp[ i ][ T ] = max(r1,r2);
}
int main(){

    op
    file();

    bool f = 0;

    while(cin >> cap >> w){

        if( f ) cout << endl;
        f = 1;
        n = sc();
        vector< int > v( n + 5 ),v1( n + 5 ),v2( n + 5 ),p( n + 5 ),a( n + 5 );
        swap(v,tim);
        swap(v1,cost);
        swap(v2,vec);
        path.clear();
        memset(dp,-1,sizeof dp);

        lop(0,n){

            int a = sc(),b = sc();
            cost[ i ] = b;
            tim[ i ] = a;
            vec[ i ] = 3 * (a * w);
        }

        int result = knapsack(0,0);

        knapsackpath(0,0);

        cout << result << endl << path.size() << endl;

        lop(0,path.size()) cout << tim[ path[ i ] ] << " " << cost[ path[ i ] ] << endl;
    }
    return 0;
}
