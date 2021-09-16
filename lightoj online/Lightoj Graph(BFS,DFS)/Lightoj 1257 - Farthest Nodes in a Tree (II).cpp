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

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){}
    data(int x_,int y_) { x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }
};

const ll inf = 1e18;
const ll infi = -(1e18);
const int mx = 1e6;
ull tk;
int source;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
vector< vector < pll > > graph;
bool vis[ 30010 ];
ll dis1[ 30010 ];
ll dis2[ 30010 ];

ll sc(){ ll n; scanf("%lld",&n); return n; }

void dfs(ll node,ull cost){

    if(vis[ node ]) return;

    vis[ node ] = 1;

    if(cost > tk) {

        tk = cost;
        source = node;
    }
    for(auto x : graph[ node ]) dfs(x.f,cost+x.s);
}

void dfs1(ll node,ull cost){

    if(vis[ node ]) return;

    vis[ node ] = 1;

    dis1[ node ] = cost;

    //cout << node << "dfs1 "<< dis1[ node ] << endl;

    if(cost > tk) {

        tk = cost;
        source = node;
    }
    for(auto x : graph[ node ]) dfs1(x.f,cost+x.s);
}

void dfs2(ll node,ull cost){

    if(vis[ node ]) return;

    vis[ node ] = 1;

    dis2[ node ] = cost;

    for(auto x : graph[ node ]) dfs2(x.f,cost+x.s);
}

int main(){

    file();

    ll test = sc();

    //cout << test << endl;

    Lop(cs,1,test+1,1) {

        ll node = sc();

        vector< vector < pll > > temp( node+5 );
        swap(graph,temp);

        lop(0,node-1){

            ll a = sc(),b = sc(),c = sc();
            graph[ a ].p_b({b,c});
            graph[ b ].p_b({a,c});
        }
        printf("Case %d:\n",cs);
        memset(vis,false,sizeof vis);
        tk = 0;
        dfs(0,0);
        memset(vis,false,sizeof vis);
        tk = 0;
        dfs1(source,0);
        tk = 0;
        memset(vis,false,sizeof vis);
        dfs2(source,0);
        lop(0,node){

            printf("%lld\n",max(dis1[ i ],dis2[ i ]));
        }
    }

    return 0;
}
