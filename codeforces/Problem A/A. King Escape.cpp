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

int qx,qy,kx,ky,dx,dy,n;
vector< vector< bool > > vis;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

bool check(int x,int y){

    if(x == qx or y == qy) return false;
    if((qx + qy) == (x + y) or (abs(qx - qy)) == abs(x - y)) return false;
    return true;
}

bool ok(int x,int y){

    return x >= 1 and x <= n and y >= 1 and y <= n;
}
void BFS(int x,int y){

    queue< pii > q;

    vis[ x ][ y ] = true;

    q.push({x,y});

    while( !q.empty() ){

        pii p = q.front();
        q.pop();

        if(vis[ dx ][ dy ]) return;

        for(int i = 0; i < 8; i++){

            int x1 = p.ft + X[ i ];
            int y1 = p.sd + Y[ i ];

            if(vis[ x1 ][ y1 ] == false and check(x1,y1) and ok(x1,y1)){

                vis[ x1 ][ y1 ] = true;

                q.push({x1,y1});
            }
        }
    }
}
int main(){

    //file();

    cin >> n;

    vis.resize(n+3,vector<bool>(n+3,false));

    cin >> qx >> qy;
    cin >> kx >> ky;
    cin >> dx >> dy;

    BFS(kx,ky);

    if(vis[ dx ][ dy ]) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

