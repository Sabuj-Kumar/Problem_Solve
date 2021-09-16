#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair< int,int >
#define f first
#define s second
#define p_b push_back
#define ull unsigned long long
#define in freopen("input.txt","r",stdin);
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x_,int y_) { x = x_,y = y_; }
    data(int x_,int y_,int c_) { x = x_,y = y_,c = c_; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

const int mx = 1e6;
const ll inf = 1e18;
const ll inf_ = -1e18;
int n,m,f;
string s[ 30 ];
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int vis[ 32 ][ 32 ];

int sc() { int n; scanf("%d",&n); return n; }

bool check(int x,int y){

    return (x >= 0 && x < n && y >= 0 && y < m && s[ x ][ y ] != '#' && s[ x ][ y ] != 'm' && vis[ x ][ y ] == -1);
}

void bfs(int u,int v,int ax,int ay,int bx,int by,int cx,int cy){

    queue< pii > q;

    q.push({u,v});

    vis[ u ][ v ] = 0;

    while(!q.empty()){

        pii a = q.front();

        q.pop();

        lop(0,4){

            int x = a.f + X[ i ];
            int y = a.s + Y[ i ];

            if(check(x,y)){

                vis[ x ][ y ] = vis[ a.f ][ a.s ] + 1;

                q.push({x,y});
            }
            if(vis[ ax ][ ay ] != -1 && vis[ bx ][ by ] != -1 && vis[ cx ][ cy ] != -1) return;
        }
    }
}
int main(){

    file();

    int test = sc();

    Lop(cs,1,test+1,1){

        n = sc();
        m = sc();
        int x = -1,y = -1,ax = -1,ay = -1,bx = -1,by = -1,cx = -1,cy = -1;

        lop(0,n) cin >> s[ i ];

        memset(vis,-1,sizeof vis);

        Lop(i,0,n,1)
            Lop(j,0,m,1) vis[ i ][ j ] = -1;

        Lop(i,0,n,1){

            Lop(j,0,m,1){

                if(s[ i ][ j ] == 'h' || s[ i ][ j ] == 'a' || s[ i ][ j ] == 'b' || s[ i ][ j ] == 'c') {

                    if(s[ i ][ j ] == 'h'){

                        x = i;
                        y = j;
                    }
                    else if(s[ i ][ j ] == 'a'){

                        ax = i;
                        ay = j;
                    }
                    else if(s[ i ][ j ] == 'b'){

                        bx = i;
                        by = j;
                    }
                    else if(s[ i ][ j ] == 'c'){

                        cx = i;
                        cy = j;
                    }
                }
            }
            if(x != -1 && ax != -1 && bx != -1 && cx != -1) break;
        }

        bfs(x,y,ax,ay,bx,by,cx,cy);

        cout << "Case " << cs << ": " << max(vis[ ax ][ ay ],max(vis[ bx ][ by ],vis[ cx ][ cy ])) << endl;
    }
    return 0;
}
