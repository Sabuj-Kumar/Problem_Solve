#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 4 * 1e5 + 10;
int tree[ N ][ 3 ];
int lazy[ N ];

void Push(int node,int mod){

    int v[ 3 ];

    for(int i = 0; i < 3; i++){

        int x = ((i - mod) < 0) ? (i - mod) + 3 : (i - mod);

        v[ i ] = tree[ node ][ x ];
    }

    for(int i = 0; i < 3; i++) tree[ node ][ i ] = v[ i ];

    lazy[ node ] += mod;
}

void build(int node,int L,int R){

    if(L == R){

        lazy[ node ] = 0;
        tree[ node ][ 0 ] = 1;
        tree[ node ][ 1 ] = tree[ node ][ 2 ] = 0;

        return;
    }

    lazy[ node ] = 0;

    int mid = (L + R) / 2;

    build(node * 2,L,mid);
    build(node * 2 + 1,mid + 1,R);

    for(int i = 0; i < 3; i++) tree[ node ][ i ] = tree[ node * 2 ][ i ] + tree[ node * 2 + 1 ][ i ];

    return;
}
void update(int node,int L,int R,int l,int r){

    if(l > r) return;

    if(l == L and R == r){

        lazy[ node ]++;

        int tmp = tree[ node ][ 2 ];
        tree[ node ][ 2 ] = tree[ node ][ 1 ];
        tree[ node ][ 1 ] = tree[ node ][ 0 ];
        tree[ node ][ 0 ] = tmp;

        return;
    }

    if(lazy[ node ]){

        Push(node * 2,lazy[ node ] % 3);
        Push(node * 2 + 1,lazy[ node ] % 3);

        lazy[ node ] = 0;
    }

    int mid = (L + R) / 2;

    update(node * 2,L,mid,l,min(mid,r));
    update(node * 2 + 1,mid + 1,R,max(mid + 1,l),r);

    for(int i = 0; i < 3; i++) tree[ node ][ i ] = tree[ node * 2 ][ i ] + tree[ node * 2 + 1 ][ i ];

    return;
}

int query(int node,int L,int R,int l,int r){

    if(l > r) return 0;

    if(l == L and R == r) return tree[ node ][ 0 ];

    if(lazy[ node ]){

        Push(node * 2,lazy[ node ] % 3);
        Push(node * 2 + 1,lazy[ node ] % 3);
        lazy[ node ] = 0;
    }

    int mid = (L + R) / 2;

    int p = query(node * 2,L,mid,l,min(mid,r));
    int q = query(node * 2 + 1,mid + 1,R,max(mid + 1,l),r);

    for(int i = 0; i < 3; i++) tree[ node ][ i ] = tree[ node * 2 ][ i ] + tree[ node * 2 + 1 ][ i ];

    return p + q;
}
int main(){

    file();

    int t = I();

    Case( t ){

        int n = I(),m = I();

        build(1,1,n);

        printf("Case %d:\n",cs);

        for(int i = 0; i < m; i++){

            int clk = I(),l = I(),r = I();

            l++;
            r++;

            if( !clk ) update(1,1,n,l,r);

            else printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}
