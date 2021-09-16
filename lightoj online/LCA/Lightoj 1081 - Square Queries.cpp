/**
    2D Segment Tree
    time complexity O(logn * logm)
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
#define pb push_back
#define pf push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define scl( n ) scanf("%I64d",&n)
#define scll( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
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
    bool operator < (const data &a) const {
        return c > a.c;
    }
};
int n,q;
vector< vector< int > > grid;
int tree[ 4 * N ][ 4 * N ];
void build_y(int nodeX,int Lx,int Rx,int nodeY,int Ly,int Ry){
    if(Ly == Ry){
        if(Lx == Rx) tree[ nodeX ][ nodeY ] = grid[ Lx ][ Ly ];
        else tree[ nodeX ][ nodeY ] = max(tree[ nodeX * 2 ][ nodeY ],tree[ nodeX * 2 + 1 ][ nodeY ] );
        return;
    }
    int midY = (Ly + Ry) / 2;
    build_y(nodeX,Lx,Rx,nodeY*2,Ly,midY);
    build_y(nodeX,Lx,Rx,nodeY*2+1,midY+1,Ry);
    tree[ nodeX ][ nodeY ] = max(tree[ nodeX ][ nodeY * 2 ],tree[ nodeX ][ nodeY * 2 + 1 ]);
}
void build_x(int nodeX,int Lx,int Rx){
    if(Lx != Rx){
        int midX = (Lx + Rx) / 2;
        build_x(nodeX*2,Lx,midX);
        build_x(nodeX*2 + 1,midX+1,Rx);
    }
    build_y(nodeX,Lx,Rx,1,0,n-1);
}
void update_y(int nodeX,int Lx,int Rx,int nodeY,int L,int R,int x,int y,int value){
    if(L == R){
        if(Lx == Rx) tree[ nodeX ][ nodeY ] = value;
        else tree[ nodeX ][ nodeY ] = max(tree[ nodeX * 2 ][ nodeY ],tree[ nodeX * 2 + 1 ][ nodeY ]);
        return;
    }
    int mid =(L + R) / 2;
    if(y <= mid) update_y(nodeX,Lx,Rx,nodeY * 2,L,mid,x,y,value);
    else update_y(nodeX,Lx,Rx,nodeY * 2 + 1,mid+1,R,x,y,value);
    tree[ nodeX ][ nodeY ] = max(tree[ nodeX ][ nodeY * 2 ],tree[ nodeX ][ nodeY * 2 + 1 ]);
}
void update_x(int nodeX,int L,int R,int x,int y,int value){
    if(L != R){
        int mid = (L + R) / 2;
        if(x <= mid) update_x(nodeX*2,L,mid,x,y,value);
        else update_x(nodeX*2+1,mid+1,R,x,y,value);
    }
    update_y(nodeX,L,R,1,0,n-1,x,y,value);
}
int query_y(int nodeX,int nodeY,int L,int R,int Ly,int Ry){
    if(Ly > Ry) return 0;
    if(L == Ly and Ry == R) return tree[ nodeX ][ nodeY ];
    int mid = (L + R) / 2;
    int q1 = query_y(nodeX,nodeY * 2,L,mid,Ly,min(mid,Ry));
    int q2 = query_y(nodeX,nodeY * 2 + 1,mid + 1,R,max(Ly,mid + 1),Ry);
    return max(q1,q2);
}
int query_x(int nodeX,int L,int R,int Lx,int Rx,int Ly,int Ry){
    if(Lx > Rx) return 0;
    if(L == Lx and Rx == R) return query_y(nodeX,1,0,n-1,Ly,Ry);
    int mid = (L + R) / 2;
    int q1 = query_x(nodeX * 2,L,mid,Lx,min(Rx,mid),Ly,Ry);
    int q2 = query_x(nodeX * 2 + 1,mid + 1,R,max(Lx,mid + 1),Rx,Ly,Ry);
    return max(q1,q2);
}
int main(){
    file();
    int t;
    sc( t );
    Case( t ){
        sc( n ),sc( q );
        vector< vector< int > > vec( n+5,vector< int > ( n+5 ));
        swap(grid,vec);
        Lop(i,0,n)
        Lop(j,0,n)
        sc(grid[ i ][ j ]);
        memset(tree,-1,sizeof tree);
        build_x(1,0,n-1);
        cout << "Case " << cs << ":" << endl;
        while( q-- ){
            int x,y,x1,y1,s;
            sc3(x,y,s);
            x--,y--;
            x1 = x + s - 1;
            y1 = y + s - 1;
            cout << query_x(1,0,n-1,x,x1,y,y1) << endl;
        }
    }
    return 0;
}
