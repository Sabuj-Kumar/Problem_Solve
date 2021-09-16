#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define pi acos(-1)
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data{

    int x,y,cost;
    data(){}
    data(int x_,int y_){ x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }

//    bool operator < ( const data &a ) const {
//
//        return cost > a.cost;
//    }
};

ll gcd(ll a,ll b){

    if(b == 0) return a;
    return gcd(b,a%b);
}

const int mx = 1e6;
const int mx_= 1e9;
const ll mx__=1e18;
const int N = 1e6 + 7;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932; // P inverse modulo M
const ll M = 1e9 + 7;

int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,1,-1,-1,1 };

int sc(){ int n; cin >> n; return n; }
ll scl(){ ll n; cin >> n; return n; }
ull scu(){ ull n; cin >> n; return n; }
string scs(){ string s; cin >> s; return s; }
string scss(){ string s; getline(cin,s); return s; }

vector < vector < pii > > graph;
bool vis[ 30005 ];

ll count_,start;

void dfs(int node,ll cost){

    if(vis[ node ]) return;

    vis[ node ] = 1;

    if(cost > count_){

        count_ = cost;
        start =  node;
    }
    for(auto x : graph[ node ]) dfs(x.f,cost+x.s);
}
int main(){

    file();

    int test = sc();

    lop(cs,1,test+1,1){

        int node = sc();
        vector< vector< pii > > temp(node + 5);
        swap(temp,graph);

        lop(i,1,node,1){

            int a = sc(),b = sc(),tk = sc();
            graph[ a ].p_b({ b,tk });
            graph[ b ].p_b({ a,tk });
        }

        memset(vis,0,sizeof vis);
        count_ = 0;
        dfs(0,0);
        memset(vis,0,sizeof vis);
        count_ = 0;
        dfs(start,0);
        cout << "Case "<< cs << ": " << count_ << endl;
    }

    return 0;
}


