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
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define in freopen("input.txt","r",stdin);
#define op sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x_,int y_) { x = x_,y = y_; }
    data(int x_,int y_,int c_) { x = x_,y = y_,c = c_; }

//    bool operator < (const data &a) const {
//
//        return c > a.c;
//    }
};

const int inf = 1e6;
const ll mx = 1e18;
const int inf_ = -1e9;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

int sc() { int n; scanf("%d",&n); return n; }
ll scc() { ll n; cin >> n; return n; }

vector< vector < int > > graph;
bool vis[ 1003 ];
int p = -1;
unordered_map< int ,int > mp;

void dfs(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    mp[ node ]++;

    if( p < mp[ node ]) p = mp[ node ];

    for(auto x : graph[ node ]) dfs( x );
}
int main(){

    file();

    int test = sc();

    Lop(cs,1,test+1,1){

        int c = 0,k = sc(),n = sc(),m = sc();
        vector< int > people;
        vector< vector< int > > v( n + 2 );
        swap(graph,v);
        mp.clear();

        lop(0,k) people.p_b( sc() );

        lop(0,m) graph[ sc() ].p_b( sc() );

        lop(0,k){

            memset(vis,false,sizeof vis);
            dfs( people[ i ] );
        }

        cout << "Case " << cs << ": ";

        if(p == k){

            lop(1,n+1) if(mp[ i ] == p) c++;
            cout << c << endl;
        }
        else cout << "0" <<endl;
    }

    return 0;
}
