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
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("input.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){}
    data(int x,int y) { this-> x = x,this -> y = y;}
    data(int x,int y,int cost) { this -> x = x,this -> y = y,this -> cost = cost; }

    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

const int sz = 1e5 + 5;
const int inf = 1e9;
const ll mx = 1e18;
const ll mx_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int Hx[ ] = {2,-2,1,-1,2,-2,1,-1};
int Hy[ ] = {1,1,2,2,-1,-1,-2,-2};

int sc() { int n; cin >> n; return n; }

vector < int > vec;
int dp[ 120 ][ sz ];
int n,cap;

int knapsack(int i,int sum){

    if(i == n) return 0;

    if(dp[ i ][ sum ] != -1) return dp[ i ][ sum ];

    ll v1 = 0,v2 = 0;

    if(sum + vec[ i ] <= cap) v1 = vec[ i ] + knapsack(i+1,sum+vec[ i ]);
    else v1 = 0;

    v2 = knapsack(i+1,sum);

    return dp[ i ][ sum ] = max(v1,v2);
}
int main(){

    op
    file();

    int t = sc();

    while( t-- ){

        n = sc();

        vector< int > v(n + 5);
        swap(vec,v);
        int sum = 0;

        lop(0,n) vec[ i ] = sc(),sum += vec[ i ];
        memset(dp,-1,sizeof dp);

        cap = sum/2;

        int result = knapsack(0,0);

        printf("%d\n",sum - 2*result);
    }
    return 0;
}
