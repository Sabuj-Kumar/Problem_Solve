#include<bits/stdc++.h>
#define lop(i,n) for(int i = 0; i < n; i++)
#define lop_(i,n) for(int i = n-1; i >= 0; i--)
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define in freopen("in.txt","r",stdin)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define f first
#define s second
#define mx 1000

using namespace std;

struct data{

    int x,y,cost;

    data(){}

    data(int x_,int y_,int cost_) {  x = x_ , y = y_, cost = cost_; }

    bool operator < (const data &z) const{

        return cost > z.cost;
    }
};

void f_in(){

    #ifndef ONLINE_JUDGE
    in;
    #endif
}

int sc(){ int n; scanf("%d",&n); return n; }
void pf(ll ans) { printf("%lld\n",ans); }
inline bool check(int row,int col,int x,int y) { return x >= 0 and x < row and y >=0 and y < col; }

const int inf = 0x3f3f3f3f;
int grid[ mx ][ mx ];
int cost[ mx ][ mx ];
int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };

ll dijstra(pii a,pii b,int row,int col){

    memset(cost,-1,sizeof cost);

    priority_queue< data > q;

    q.push( data( a.f, a.s, grid[ a.f ][ a.s ] ) );

    cost[ a.f ][ a.s ] = grid[ a.f ][ a.s ];

    while(!q.empty()){

        auto top = q.top();

        q.pop();

        if(top.cost > cost[ top.x ][ top.y ]) continue;

        for(int i = 0; i < 4; i++){

            int x = top.x + X[ i ];
            int y = top.y + Y[ i ];

            if(!check(row,col,x,y)) continue;

            if(cost[ x ] [ y ] == -1 or cost[ x ][ y ] > grid[ x ][ y ] + cost[ top.x ][ top.y ]){

                cost[ x ][ y ] = grid[ x ][ y ] + cost[ top.x ][ top.y ];

                q.push(data(x,y,cost[ x ][ y ]));
            }
        }
    }

    return cost[ b.f ][ b.s ];
}
int main(){

    f_in();
    optimizar;

    int test = sc();

    while( test-- ){

        int row = sc(),col = sc();

        lop(i,row)
            lop(j,col) grid[ i ][ j ] = sc();

        ll ans = dijstra(pii(0,0),pii(row-1,col-1),row,col);

        pf(ans);
    }

    return 0;
}
