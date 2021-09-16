/**
  LCA COMPLEXITY O( n )
**/

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
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);
using namespace std;
const int sz = 1e5 + 10;
const int inf = 1e9;
const ll mx_ = 1e18;
const ll inf_ = -1e18;
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
        return c < a.c;
    }
}grid[ sz ];
int node,edge,way;
int p[ sz ],level[ sz ];
int mx[ sz ][ 30 ],table[ sz ][ 30 ];
vector< pii > graph[ sz ];
int sc() { int n; scanf("%d",&n); return n; }
void dfs(int child,int baba,int lebel,int danger){

    table[ child ][ 0 ] = baba;
    level[ child ] = lebel;
    mx[ child ][ 0 ] = danger;
    for(auto v : graph[ child ])
        if(level[ v.f ] == -1 and v.f != child)
            dfs(v.f,child,lebel+1,v.s);
}
int find_parent(int a){
    if(a == p[ a ]) return a;
    else return p[ a ] = find_parent(p[ a ]);
}
void mst(){
    lop(0,node+1) p[ i ] = i;
    sort(grid,grid+edge);
    int n = 0,l = 0;
    while(l < edge and n < node -1 ){

        data a = grid[ l ];
        int px = find_parent( a.x );
        int py = find_parent( a.y );
        if(px != py){
            n++;
            p[ py ] = px;
            graph[ a.x ].p_b({a.y,a.c});
            graph[ a.y ].p_b({a.x,a.c});
        }
        l++;
    }
}
void sparse_table(){
    for(int i = 0; i < node; i++){
        for(int j = 1; (1 << j) < node; j++){
            table[ i ][ j ] = -1;
            mx[ i ][ j ] = -1;
        }
    }
    dfs(0,-1,0,0);
    for(int j = 1; (1 << j) < node; j++){
        for(int i = 0; i < node; i++){
            if(table[ i ][ j - 1 ] != -1){
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
                mx[ i ][ j ] = max(mx[ i ][ j - 1 ],mx[ table[ i ][ j - 1 ] ][ j - 1 ]);
            }
        }
    }
}
int LCA(int a,int b){
    if(level[ a ] < level[ b ]) swap(a,b);
    int log = 1,ans = -1;
    while( (1 << log) <= level[ a ]) ++log;
    for(int i = log; i >= 0; i--){
        if(level[ a ] - (1 << i) >= level[ b ]){
            ans = max(ans,mx[ a ][ i ]);
            a = table[ a ][ i ];
        }
    }
    if(a == b) return ans;
    for(int i = log; i >= 0; i--){
        if(table[ a ][ i ] != -1 and table[ a ][ i ] != table[ b ][ i ]){
            ans = max(ans,max(mx[ a ][ i ],mx[ b ][ i ]));
            a = table[ a ][ i ];
            b = table[ b ][ i ];
        }
    }
    ans = max(ans,max(mx[ a ][ 0 ],mx[ b ][ 0 ]));
    return ans;
}
int main(){
    file();
    int t = sc();
    Case( t ){
        node = sc();
        edge = sc();
        lop(0,edge){
            grid[ i ].x = sc()-1;
            grid[ i ].y = sc()-1;
            grid[ i ].c = sc();
        }
        memset(level,-1,sizeof level);
        mst();
        sparse_table();
        way = sc();
        cout << "Case " << cs << ":" << endl;
        while( way-- ){
            int start = sc() - 1,destination = sc() - 1;
            cout << LCA(start,destination) << endl;
        }
        lop(0,node+1) graph[ i ].clear();
    }
    return 0;
}
