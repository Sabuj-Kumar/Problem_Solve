/***
    HLD TIME COMPLEXITY  O(log^2(n));
****/
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
#define pii pair< int,int >
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
const int N = 3 * 1e4 + 5;
int sc(){ int n; scanf("%d",&n); return n; }
int n,ind,lg;
vector< int > ar;
vector < vector < int > > graph;
int table[ N ][ 25 ];
int tree[ 4 * N ],base[ N ];
int parent[ N ],level[ N ],heavy[ N ],subtree[ N ];
int head = 0,chainhead[ N ],chainnum[ N ],chainpos[ N ]; /// heavy Light
int dfs(int child,int baba,int l){
    subtree[ child ] = 1;
    level[ child ] = l;
    parent[ child ] = baba;
    int x = 0,mx = 0;
    for(auto v : graph[ child ]){
        if(v != child and level[ v ] == -1){
            x = dfs(v,child,l+1);
            subtree[ child ] += x;
            if(x > mx){
                mx = x;
                heavy[ child ] = v;
            }
        }
    }
    return subtree[ child ];
}
void sparse(){
    lg = 1;
    while(( 1<<lg ) <= n) ++lg;
    memset(level,-1,sizeof level);
    for(int j = 0; (1 << j) <= n; j++)
        for(int i = 0; i < n; i++)
            table[ i ][ j ] = -1;
    dfs(0,-1,0);
    Lop(i,0,n) table[ i ][ 0 ] = parent[ i ];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i < n; i++)
            if(table[ i ][ j - 1 ] != -1)
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}
int LCA(int u,int v){
    if(level[ u ] < level[ v ]) swap(u,v);
    lg = 1;
    while(( 1<<lg ) <= level[ u ]) ++lg;
    for(int i = lg; i >= 0; i--)
        if(level[ u ] - (1 << i) >= level[ v ])
            u = table[ u ][ i ];
    if(u == v) return u;
    for(int i = lg; i >= 0; i--)
        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ])
            u = table[ u ][ i ],v = table[ v ][ i ];
    return parent[ u ];
}
void build(int node,int L,int R){
    if(L == R){
        tree[ node ] = base[ L ];
        return;
    }
    int mid = (L + R) / 2;
    build(node * 2,L,mid);
    build(node * 2 + 1,mid+1,R);
    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}
void update(int node,int L,int R,int pos,int val){
    if(L == R){
        base[ L ] = val;
        tree[ node  ] = val;
        return;
    }
    int mid = (L + R)/2;
    if(pos <= mid) update(node * 2,L,mid,pos,val);
    else update(node * 2 + 1,mid+1,R,pos,val);
    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}
int query_tree(int node,int L,int R,int l,int r){
    if(l > r) return 0;
    if(L == l and r == R)return tree[ node ];
    int mid = (L + R) / 2;
    int q1 = query_tree(node * 2,L,mid,l,min(mid,r));
    int q2 = query_tree(node * 2 + 1,mid + 1,R,max(mid+1,l),r);
    return q1 + q2;
}
int hvlit(int node,int p){
    if(chainhead[ head ] == -1) chainhead[ head ] = node;
    chainnum[ node ] = head;
    base[ ind++ ] = ar[ node ];
    chainpos[ node ] = ind-1;
    if(heavy[ node ] >= 0) hvlit(heavy[ node ],node);
    for(auto v : graph[ node ]){
        if(v != p and v != heavy[ node ]){
            head++;
            hvlit(v,node);
        }
    }
}
int query_up(int u,int p){
    int uchain,pchain = chainnum[ p ];
    int result = 0;
    while( 1 ){
        uchain = chainnum[ u ];
        if(uchain == pchain){
            result += query_tree(1,0,n,chainpos[ p ],chainpos[ u ]);
            break;
        }
        result += query_tree(1,0,n,chainpos[ chainhead[ uchain ] ],chainpos[ u ]);
        u = chainhead[ uchain ];
        u = parent[ u ];
    }
    return result;
}
void update_hld(int p,int v){
    update(1,0,n,chainpos[ p ],v);
}
int query_hld(int u,int v){

    int l = LCA(u,v);
    int ans = query_up(u,l) + query_up(v,l) - query_up(l,l);
    return ans;
}
void init(){
    for(int i = 0; i < n; i++){
        heavy[ i ] = -1;
        chainhead[ i ] = -1;
    }
    sparse();
    head = 0;
    ind = 0;
    hvlit(0,0);
    build(1,0,n);
}
int main(){

    int t = sc();
    Case( t ){
        n = sc();
        vector< int > v1( n + 5 );
        vector< vector < int > > v( n + 5 );
        swap(graph,v);
        swap(ar,v1);
        Lop(i,0,n) ar[ i ] = sc();
        Lop(i,1,n){
            int a = sc(),b = sc();
            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }
        init();
        printf("Case %d:\n",cs);
        int q = sc();
        while( q-- ){

            int p = sc(),a = sc(),b = sc();
            if( !p )printf("%d\n",query_hld(a,b));
            else update_hld(a,b);
        }
    }
    return 0;
}
