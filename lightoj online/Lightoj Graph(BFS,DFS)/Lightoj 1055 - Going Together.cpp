#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define pf push_front
#define ph push
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define sc1( n ) scanf("%d",&n);
#define sc2( a,b ) scanf("%d %d",&a,&b)
#define sc3( a,b,c ) scanf("%d %d %d",&a,&b,&c)
#define scl( n ) scanf("%I64d",&n)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}


struct node{

    pii a,b,c;
};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int I() { int n; scanf("%d",&n); return n; }
ll Il() { ll n; scanf("%lld",&n); return n; }

int n;
string s[ 20 ];
int dis[ 12 ][ 12 ][ 12 ][ 12 ][ 12 ][ 12 ];
bool vis[ 12 ][ 12 ][ 12 ][ 12 ][ 12 ][ 12 ];

bool check(pii p){

    return p.f >= 0 and p.f < n and p.s >= 0 and p.s < n and s[ p.f ][ p.s ] != '#';
}
int BFS(node nd){

    queue< node >  Q;
    Q.ph( nd );
    dis[ nd.a.f ][ nd.a.s ][ nd.b.f ][ nd.b.s ][ nd.c.f ][ nd.c.s ] = 0;
    vis[ nd.a.f ][ nd.a.s ][ nd.b.f ][ nd.b.s ][ nd.c.f ][ nd.c.s ] = false;

    while( !Q.empty() ){

        node v = Q.front();
        Q.pop();

        if(s[ v.a.f ][ v.a.s ] == 'X' and s[ v.b.f ][ v.b.s ] == 'X' and s[ v.c.f ][ v.c.s ] == 'X' and v.a != v.b and v.b != v.c and v.a != v.c)
            return dis[ v.a.f ][ v.a.s ][ v.b.f ][ v.b.s ][ v.c.f ][ v.c.s ];

        for(int i = 0; i < 4; i++){

            node m = v;

            if( check( {v.a.f + X[ i ],v.a.s + Y[ i ]} ) ) m.a.f = v.a.f + X[ i ],m.a.s = v.a.s + Y[ i ];
            if( check( {v.b.f + X[ i ],v.b.s + Y[ i ]} ) ) m.b.f = v.b.f + X[ i ],m.b.s = v.b.s + Y[ i ];
            if( check( {v.c.f + X[ i ],v.c.s + Y[ i ]} ) ) m.c.f = v.c.f + X[ i ],m.c.s = v.c.s + Y[ i ];

            if( m.a == m.b ) { if(m.b == m.c) m.c = v.c; m.a = v.a,m.b = v.b; }
            if( m.a == m.c ) m.a = v.a,m.c = v.c;
            if( m.b == m.c ) m.b = v.b,m.c = v.c;

            if(vis[ m.a.f ][ m.a.s ][ m.b.f ][ m.b.s ][ m.c.f ][ m.c.s ]){

                vis[ m.a.f ][ m.a.s ][ m.b.f ][ m.b.s ][ m.c.f ][ m.c.s ] = false;
                dis[ m.a.f ][ m.a.s ][ m.b.f ][ m.b.s ][ m.c.f ][ m.c.s ] = 1 + dis[ v.a.f ][ v.a.s ][ v.b.f ][ v.b.s ][ v.c.f ][ v.c.s ];
                Q.ph( m );
            }
        }
    }

    return -1;
}
int main(){

    file();

    int test = I();

    Case( test ){

        n = I();

        for(int i = 0; i < n; i++) cin >> s[ i ];
        node v;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){

            if(s[ i ][ j ] == 'A') v.a.f = i,v.a.s = j;
            else if(s[ i ][ j ] == 'B') v.b.f = i,v.b.s = j;
            else if(s[ i ][ j ] == 'C') v.c.f = i,v.c.s = j;
        }

        memset(dis,0,sizeof dis);
        memset(vis,true,sizeof vis);

        int ans = BFS( v );

        if( ans == -1 )printf("Case %d: trapped\n",cs);
        else printf("Case %d: %d\n",cs,ans);
    }

    return 0;
}
