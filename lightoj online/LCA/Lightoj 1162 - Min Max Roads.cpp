/**  LCA MIN MAX sparse table **/
#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsiged long long
#define db double
#define ldb long double
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pii pair< int,int >
#define pll pair< ll,ll >
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1;  cs <= n; cs++)
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
const int N = 1e5 + 5;
const int inf = 1e9;
const int inf_ = -1e9;
const ll mxi = 1e18;
const ll mx_ = -1e18;
int X[ ] = {0,0,-1,1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};
int node,lg;
vector< pii > graph[ N ];
int level[ N ],table[ N ][ 20 ],mx[ N ][ 20 ],mn[ N ][ 20 ];
int sc(){ int n; scanf("%d",&n); return n; }

void dfs(int child,int baba,int l,int weight){

    table[ child ][ 0 ] = baba;
    level[ child ] = l;
    mx[ child ][ 0 ] = weight;
    mn[ child ][ 0 ] = weight;
    for(auto x : graph[ child ])
        if(level[ x.f ] == -1 and child != baba)
            dfs(x.f,child,l+1,x.s);
}
void sparse(){
    for(int j = 0; j <= lg; j++){
        for(int i = 0; i < node; i++){
            table[ i ][ j ] = -1;
            mx[ i ][ j ] = inf_;
            mn[ i ][ j ] = inf;
        }
    }
    dfs(0,-1,0,0);
    for(int j = 1; j <= lg; j++){
        for(int i = 0; i < node; i++){
            if(table[ i ][ j - 1 ] != -1){
                mx[ i ][ j ] = max(mx[ i ][ j - 1 ],mx[ table[ i ][ j - 1 ] ][ j - 1 ]);
                mn[ i ][ j ] = min(mn[ i ][ j - 1 ],mn[ table[ i ][ j - 1 ] ][ j - 1 ]);
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
            }
        }
    }
}
pii LCA(int u,int v){
    int mx1 = inf_,mn1 = inf;
    if(level[ u ] < level[ v ]) swap(u,v);
    lg = 1;
    while( (1 << lg) <= level[ u ]) ++lg;
    --lg;
    for(int i = lg; i >= 0; i--){
        if(level[ u ] - (1 << i) >= level[ v ]){
            mx1 = max(mx1,mx[ u ][ i ]);
            mn1 = min(mn1,mn[ u ][ i ]);
            u = table[ u ][ i ];
        }
    }
    if(u == v) return {mx1,mn1};
    for(int i = lg; i >= 0; i--){
        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ]){
            mx1 = max(mx1,max(mx[ u ][ i ],mx[ v ][ i ]));
            mn1 = min(mn1,min(mn[ u ][ i ],mn[ v ][ i ]));
            u = table[ u ][ i ];
            v = table[ v ][ i ];
        }
    }
    mx1 = max( mx1,max(mx[ u ][ 0 ],mx[ v ][ 0 ]));
    mn1 = min( mn1,min(mn[ u ][ 0 ],mn[ v ][ 0 ]));
    return {mx1,mn1};
}
int main(){
    op
    //file();
    //int t = sc();
    //Case( t ){
        int n,m,w;
        node = sc();
        memset(level,-1,sizeof level);
        lg = 1;
        while( (1 << lg) < node) ++lg;
        for(int i = 1; i < node; i++){
            n = sc()-1;
            m = sc()-1;
            w = sc();
            graph[ n ].pb({m,w});
            graph[ m ].pb({n,w});
        }
        //printf("Case %d:\n",cs);
        sparse();
        int q = sc();
        while( q-- ){
            n = sc()-1;
            m = sc()-1;
            pii ans = LCA(n,m);
            printf("%d %d\n",ans.s,ans.f);
        }
        Lop(i,0,node) graph[ i ].clear();
    ///}
    return 0;
}
