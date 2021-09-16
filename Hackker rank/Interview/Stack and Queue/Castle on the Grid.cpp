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
#define lop(i,vis,n) for(int i = vis; i < n; i++)
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

const int N = 110;

string s[ N ];
int sx,sy,dx,dy,n,vis[ N ][ N ];
queue< pii > q;

void right(int x,int y){

    for(int i = y + 1; i < n; i++) {

        if(s[ x ][ i ] == 'X' or vis[ x ][ i ] != -1) return;

        vis[ x ][ i ] = vis[ x ][ y ] + 1;

        q.push({x,i});
    }
}
void left(int x,int y){

    for(int i = y - 1; i >= 0; i--) {

        if(s[ x ][ i ] == 'X' or vis[ x ][ i ] != -1) return;

        vis[ x ][ i ] = vis[ x ][ y ] + 1;

        q.push({x,i});
    }
}
void up(int x,int y){

    for(int i = x - 1; i >= 0; i--) {

        if(s[ i ][ y ] == 'X' or vis[ i ][ y ] != -1) return;

        vis[ i ][ y ] = vis[ x ][ y ] + 1;

        q.push({i,y});
    }
}
void down(int x,int y){

    for(int i = x + 1; i < n; i++) {

        if(s[ i ][ y ] == 'X' or vis[ i ][ y ] != -1) return;

        vis[ i ][ y ] = vis[ x ][ y ] + 1;

        q.push({i,y});
    }
}
void call(int x,int y){

    up(x,y);
    right(x,y);
    left(x,y);
    down(x,y);
}
void BFS(){

    vis[ sx ][ sy ] = 0;

    q.push({sx,sy});

    while(!q.empty()){

        pii u = q.front();

        q.pop();

        if(vis[ dx ][ dy ] != -1) return;

        call(u.ft,u.sd);
    }
}
int main(){

    memset(vis,-1,sizeof vis);

    file();

    cin >> n;

    for(int i = 0; i < n; i++) cin >> s[ i ];

    cin >> sx >> sy >> dx >> dy;

    BFS();

    cout << vis[ dx ][ dy ] << endl;

    return 0;
}
