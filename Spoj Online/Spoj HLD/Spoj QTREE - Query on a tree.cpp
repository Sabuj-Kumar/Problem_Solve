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
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scl( a ) scanf("%I64d",&a)
#define scl2(a,b) scanf("%I64d %I64d",&a,&b)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
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

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

const int N = 1e4 + 5;
const int inf = 1e9;
const ll mx  = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

vector< vector< pii >  > graph;
vector< pii > vec;
int n,lg;
int tree[ 4 * N ],treecost[ N ]; /// Segment Tree
int ind,chain,chainhead[ N ],chainnum[ N ],nodepos[ N ],heavy[ N ];/// Heavy Light
int subtree[ N ],level[ N ],cost[ N ],table[ N ][ 25 ];/// LCA

int dfs(int child,int par,int l = 0,int c = 0){

    table[ child ][ 0 ] = par;
    level[ child ] = l;
    cost[ child ] = c;
    subtree[ child ] = 1;

    int x = 0,mxi = 0;

    for(auto v : graph[ child ]){

        if(v.f != par and level[ v.f ] == -1){

            x = dfs(v.f,child,l+1,v.s);

            subtree[ child ] += x;

            if(x > mxi){

                heavy[ child ] = v.f;
                mxi = x;
            }
        }
    }
    return subtree[ child ];
}

void sparce(){

    for(int j = 0; (1 << j) <= n; j++)
        for(int i = 1; i <= n; i++)
            table[ i ][ j ] = -1;

    dfs(1,-1);

    for(int j = 1; ( 1 << j ) <= n; j++)
        for(int i = 1; i <= n; i++)
            if(table[ i ][ j - 1 ] != -1)
                table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA(int u,int v){

    if(u == v) return u;

    if(level[ u ] < level[ v ]) swap(u,v);

    lg = 1;

    while( ( 1 << lg ) <= level[ u ] ) ++lg;
    lg--;

    for(int i = lg; i >= 0; i--)
        if(level[ u ] - (1 << i ) >= level[ v ])
            u = table[ u ][ i ];

    if(u == v) return u;

    for(int i = lg; i >= 0; i--)
        if(table[ u ][ i ] != -1 and table[ u ][ i ] != table[ v ][ i ])
            u = table[ u ][ i ],v = table[ v ][ i ];

    return table[ u ][ 0 ];
}

void build(int node,int L,int R){

    if(L == R) {

        tree[ node ] = treecost[ L ];
        return;
    }

    int mid = (L + R) >> 1;
    build(node * 2,L,mid);
    build(node * 2 + 1,mid + 1,R);
    tree[ node ] = max(tree[ node * 2 ],tree[ node * 2 + 1 ]);
}

void update(int node,int L,int R,int pos,int val){

    if(L == R) {

        tree[ node ] = val;
        return;
    }

    int mid = (L + R) >> 1;
    if(pos <= mid) update(node * 2,L,mid,pos,val);
    else update(node * 2 + 1,mid + 1,R,pos,val);
    tree[ node ] = max(tree[ node * 2 ],tree[ node * 2 + 1 ]);
}

int query(int node,int L,int R,int l,int r){

    if( l > r )return 0;

    if(L == l and r == R) return tree[ node ];

    int mid = (L + R) >> 1;
    int p1 = query(node * 2,L,mid,l,min(r,mid));
    int p2 = query(node * 2 + 1,mid + 1,R,max(mid + 1,l),r);
    return max(p1,p2);
}

void HLD(int node,int P){

    if(chainhead[ chain ] == -1) chainhead[ chain ] = node;
    chainnum[ node ] = chain;
    treecost[ ind++ ] = cost[ node ];
    nodepos[ node ] = ind - 1;

    if(heavy[ node ] > -1) HLD(heavy[ node ],node);

    for(auto x : graph[ node ]){

        if(x.f != P and x.f != heavy[ node ]){

            chain++;
            HLD(x.f,node);
        }
    }
}

int HLDQuery(int u,int v){

    if(u == v) return 0;

    int uchain,vchain = chainnum[ v ];

    int ans = 0;

    while( 1 ){

        uchain = chainnum[ u ];

        if(uchain == vchain){

            if(u == v) break;
            ans = query(1,1,ind-1,nodepos[ v ],nodepos[ u ]);
            break;
        }

        ans = query(1,1,ind-1,nodepos[ chainhead[ uchain ] ],nodepos[ u ]);
        u = chainhead[ uchain ];
        u = table[ u ][ 0 ];
    }
    return ans;
}

void change(int pos,int value){

    pos--;
    int u = vec[ pos ].f;
    int v = vec[ pos ].s;
    if(table[ u ][ 0 ] != v) swap(u,v);
    update(1,1,ind-1,nodepos[ u ],value);
}
void Init(){

    ind = 1;
    chain = 1;
    lg = 1;
    for(int i = 0; i <= n; i++) chainnum[ i ] = -1,heavy[ i ] = -1,level[ i ] = -1;
    sparce();
    HLD(1,1);
    build(1,1,ind-1);
}
int main(){

    file();

    int t;

    scanf("%d",&t);

    while( t-- ){

        scanf("%d",&n);

        int a,b,c;
        vector< vector< pii > > v( n + 5 );
        vector< pii > v1( n + 5);
        swap(v,graph);
        swap(vec,v1);

        for(int i = 0; i < n-1; i++){

            scanf("%d %d %d",&a,&b,&c);
            graph[ a ].pb({b,c});
            graph[ b ].pb({a,c});
            vec.pb({a,b});
        }

        Init();

        while( 1 ){

            char s[ 30 ];

            scanf("%s",s);

            if(s[ 0 ] == 'D') break;

            scanf("%d %d",&a,&b);

            if(s[ 0 ] == 'Q'){

                int lca = LCA(a,b);
                printf("%d\n",max(HLDQuery(a,lca),HLDQuery(b,lca)));
            }
            else change(a,b);
        }

        if(t > 0) printf("\n");
    }

    return 0;
}

