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

int n,m;
int vis[ 110 ][ 110 ];
int vis1[ 110 ][ 110];
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}

void BFS(int x,int y){

    memset(vis,-1,sizeof vis);

    queue< pii > q;

    vis[ x ][ y ] = 0;

    q.push({x,y});

    while(!q.empty()){

        pii p = q.front();

        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = p.ft + X[ i ];
            int yy = p.sd + Y[ i ];

            if(check(xx,yy) and vis[ xx ][ yy ] == -1){

                vis[ xx ][ yy ] = vis[ p.ft ][ p.sd ] + 1;

                q.push({xx,yy});
            }
        }
    }
}

void BFS1(int x1,int y1,int x2,int y2){

    memset(vis1,-1,sizeof vis1);

    vis1[ x1 ][ y1 ] = vis1[ x2 ][ y2 ] = 0;

    queue< pii > q;

    q.push({x1,y1});
    q.push({x2,y2});

    while(!q.empty()){

        pii p = q.front();

        q.pop();

        for(int i = 0; i < 4; i++){

            int x = p.ft + X[ i ];
            int y = p.sd + Y[ i ];

            if(check(x,y) and vis1[ x ][ y ] == -1){

                vis1[ x ][ y ] = vis1[ p.ft ][ p.sd ] + 1;

                q.push({x,y});
            }
        }
    }
}
int main(){

    //file();

    int k;

    scanf("%d %d",&n,&m);
    scanf("%d",&k);

    while(k--){

        int rx,ry,cx1,cy1,cx2,cy2;

        scanf("%d %d %d %d %d %d",&rx,&ry,&cx1,&cy1,&cx2,&cy2);

        BFS(rx-1,ry - 1);

        BFS1(cx1-1,cy1 - 1,cx2 - 1,cy2 - 1);

        bool flag = false;

        for(int i = 0; i < n; i++) { if(vis[ i ][ 0 ] < vis1[ i ][ 0 ]) flag = true; }
        for(int i = 0; i < n; i++) { if(vis[ i ][ m-1 ] < vis1[ i ][ m-1 ]) flag = true; }
        for(int i = 0; i < m; i++) { if(vis[ 0 ][ i ] < vis1[ 0 ][ i ]) flag = true; }
        for(int i = 0; i < m; i++) { if(vis[ n - 1 ][ i ] < vis1[ n - 1 ][ i ]) flag = true; }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
