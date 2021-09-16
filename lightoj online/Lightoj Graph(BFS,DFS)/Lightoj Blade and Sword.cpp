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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

struct node{

    int x;
    int y;
    int fg;
};
const int N = 210;
int vis[ N ][ N ][ 2 ];
int lvl[ N ][ N ][ 2 ];
string s[ N ];
vector< pii > v;
int xp,yp,xd,yd,m,n;
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m and s[ x ][ y ] != '#';
}
bool BFS(int cs){

    queue< node > q;

    q.push({xp,yp,0});

    vis[ xp ][ yp ][ 0 ] = cs;
    lvl[ xp ][ yp ][ 0 ] = 0;

    while(!q.empty()){

        node p = q.front();

        q.pop();

        if(p.x == xd and p.y == yd) return true;

        if(s[ p.x ][ p.y ] == '*'){

            for(int i = 0; i < v.size(); i++){

                int xx = v[ i ].ft;
                int yy = v[ i ].sd;

                if(xx == p.x and yy == p.y or vis[ xx ][ yy ][ 1 ] == cs) continue;

                vis[ xx ][ yy ][ 1 ] = cs;

                lvl[ xx ][ yy ][ 1 ] = lvl[ p.x ][ p.y ][ p.fg ] + 1;

                q.push({xx,yy,1});
            }

            v.clear();
            v.pb({p.x,p.y});
        }

        if(s[ p.x ][ p.y ] != '*' or (s[ p.x ][ p.y ] == '*' and p.fg)){

            for(int i = 0; i < 4; i++){

                int xx = p.x + X[ i ];
                int yy = p.y + Y[ i ];

                if(check(xx,yy) and vis[ xx ][ yy ][ 0 ] != cs){

                    lvl[ xx ][ yy ][ 0 ] = lvl[ p.x ][ p.y ][ p.fg ] + 1;
                    vis[ xx ][ yy ][ 0 ] = cs;
                    q.push({xx,yy,0});
                }
            }
        }
    }

    return vis[ xd ][ yd ][ 0 ] == cs;
}

int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        v.clear();

        cin >> n >> m;

        for(int i = 0; i < n; i++){

            cin >> s[ i ];

            for(int j = 0; j < m; j++){

                if(s[ i ][ j ] == 'P') { xp = i; yp = j; }
                else if(s[ i ][ j ] == 'D') { xd = i; yd = j; }
                else if(s[ i ][ j ] == '*') v.pb({i,j});
            }
        }

        if(BFS(cs)) cout << "Case " << cs << ": " << lvl[ xd ][ yd ][ 0 ] << endl;

        else cout << "Case " << cs << ": impossible" << endl;
    }
    return 0;
}
