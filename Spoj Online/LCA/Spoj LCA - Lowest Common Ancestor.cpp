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
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data{

    int x,y,c;
    data(){}
    data(int x,int y){ this-> x = x,this-> y = y; }
    data(int x,int y,int c){ this->x = x,this->y = y,this-> c = c; }
    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int sz = 1e6;
const int mx = 1e9;
const ll inf = 1e18;
const ll inf_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int Hx[ ] = {1,1,2,2,-1,-1,-2,-2};
int Hy[ ] = {2,-2,1,-1,2,-2,1,-1};

const int N = 1e3+5;
int pr[ N ];
int level[ N ];
int table[ N ][ 50 ];

int sc() { int n; cin >> n; return n; }

void dfs(int u,int p,int l,vector< vector< int > > &graph){

    pr[ u ] = p;
    level[ u ] = l;
    for(auto v : graph[ u ]) if(v != u && level[ v ] == -1) dfs(v,u,l+1,graph);
}
void sp_tbl(int n,vector< vector< int > > &v){

    dfs(1,-1,0,v);

    memset(table,-1,sizeof table);

    for(int i = 0; i <= n; i++) table[ i ][ 0 ] = pr[ i ];

    for(int j = 1; (1<<j) < n; j++){

        for(int i = 1; i <= n; i++){

            if(table[ i ][ j - 1 ] != -1) table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
        }
    }
}

int LCA(int n,int u,int v){

    if(level[ u ] < level[ v ]) swap(u,v);

    int logn = 0;

    while((1<<(1+logn)) <= n) ++logn;

    for(int i = logn; i >= 0; i--)
        if(level[ u ] - (1 << i) >= level[ v ]) u = table[ u ][ i ];

    if(u == v) return u;

    for(int i = logn; i >= 0; i--){

        if(table[ u ][ i ] != -1 && table[ u ][ i ] != table[ v ][ i ]){

            u = table[ u ][ i ];
            v = table[ v ][ i ];
        }
    }
    return pr[ u ];
}

int main(){

    op
    file();

    int test = sc();

    Lop(cs,1,test+1,1){

        int n = sc(),q;
        memset(pr,-1,sizeof pr);
        memset(level,-1,sizeof level);

        vector< vector< int > > graph( n+2 );

        Lop(i,1,n+1,1){

            q = sc();
            Lop(j,0,q,1) {

                int x = sc();
                graph[ i ].push_back( x );
                graph[ x ].push_back( i );
            }
        }

        q = sc();

        sp_tbl(n,graph);

        cout << "Case " << cs << ": " << endl;

        while( q-- ){

            int u = sc(),v = sc();

            cout << LCA(n,u,v) << endl;
        }
    }
    return 0;
}
