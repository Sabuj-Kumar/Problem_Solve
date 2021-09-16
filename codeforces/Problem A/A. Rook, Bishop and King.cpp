#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e3 + 10;

int dx,dy,n;
int vis[ 10 ][ 10 ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

int rock(int x,int y){

    if(x == dx or y == dy) return 1;
    return 2;
}

int bishop(int x,int y){

    int x1 = abs(x - y) % 2;
    int y1 = abs(dx - dy) % 2;

    if(x1 == y1){

        if( abs(x - dx) == abs(y - dy) or (x + y) == (dx + dy) ) return 1;
        return 2;
    }
    return 0;
}
bool ok(int x,int y){

    return x >= 1 and x <= 8 and y >= 1 and y <= 8;
}
void BFS(int x,int y){

    queue< pii > q;

    vis[ x ][ y ] = 0;

    q.push({x,y});

    while( !q.empty() ){

        pii p = q.front();

        q.pop();

        for(int i = 0; i < 8; i++){

            int x1 = p.ft + X[ i ];
            int y1 = p.sd + Y[ i ];

            if(ok(x1,y1) and vis[ x1 ][ y1 ] == -1){

                vis[ x1 ][ y1 ] = vis[ p.ft ][ p.sd ] + 1;

                q.push({x1,y1});
            }
        }
    }
}
int main(){

    //file();
    int x,y;

    cin >> x >> y;
    cin >> dx >> dy;

    memset(vis,-1,sizeof vis);

    int b = bishop(x,y);
    int r = rock(x,y);
    BFS(x,y);

    int k = vis[ dx ][ dy ];

    cout << r << " " << b << " " << k << endl;

    return 0;
}


