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
#define op ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct Node{

    int x,y,z;
};
int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int P = 1;
int n,m,r;
int X[ ] = {0,0,0,1,-1};
int Y[ ] = {0,1,-1,0,0};
int grid[ 12 ][ 22 ][ 22 ];
int vis[ 12 ][ 22 ][ 22 ];

int BFS(){

    Node q[ 22 * 22 ];
    memset(vis,-1,sizeof vis);

    int start = 0,end_ = 0;

    Node temp;

    temp.x = 1;
    temp.y = 1;
    temp.z = 0;

    vis[ 0 ][ 1 ][ 1 ] = 0;

    q[ end_++ ] = temp;

    while(start != end_){

        Node u = q[ start++ ];

        if(start == end_) start = 0,end_ = 0;

        for(int i = 0; i < 5; i++){

            Node v;
            v.x = u.x + X[ i ];
            v.y = u.y + Y[ i ];
            v.z = (u.z + 1) % r;

            if(grid[ v.z ][ v.x ][ v.y ] == P and vis[ v.z ][ v.x ][ v.y ] == -1){

                vis[ v.z ][ v.x ][ v.y ] = vis[ u.z ][ u.x ][ u.y ] + 1;

                if(v.x == n and v.y == m) return vis[ v.z ][ v.x ][ v.y ];

                q[ end_++ ] = v;
            }
        }
    }

    return -1;
}
int main(){

    file();

    int cs = 0;

    while(cin >> n >> m >> r and n and m and r){

        for(int i = 0; i < r; i++){

            for(int j = 1; j <= n; j++){

                for(int k = 1; k <= m; k++){

                    char ch;

                    cin >> ch;

                    grid[ i ][ j ][ k ] = ch - '0' + 1;
                }
            }
        }

        int ans = BFS();

        if(ans == -1) cout << "Case " << ++cs << ": Luke and Leia cannot escape." << endl;
        else cout << "Case " << ++cs << ": Luke and Leia can escape in " << ans << " steps." << endl;
    }

    return 0;
}
