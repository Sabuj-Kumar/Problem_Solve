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

const int N = 22;
string s[ N ];
bool vis[ N ][ N ];
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int n,m,sx,sy,ex,ey;

bool ok(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}

bool check(){

    int cnt = 0;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if( (i == 0 or i == n - 1 or j == 0 or j == m - 1) and s[ i ][ j ] == '.'){

                if(cnt == 0){
                    sx = i;
                    sy = j;
                }
                else if(cnt == 1){

                    ex = i;
                    ey = j;
                }
                else return false;

                cnt++;
            }
        }
    }

    if(cnt == 2) return true;
    else return false;
}
bool DFS(int r,int c){

    if(r == ex and c == ey) return true;

    if(vis[ r ][ c ]) return false;

    vis[ r ][ c ] = true;

    for(int i = 0; i < 4; i++){

        int x = r + X[ i ];
        int y = c + Y[ i ];

        if(ok(x,y) and s[ x ][ y ] == '.')
            if(DFS(x,y)) return true;
    }

    return false;
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        cin >> n >> m;

        memset(vis,false,sizeof vis);

        for(int i = 0; i < n; i++) cin >> s[ i ];

        if(n == 1 and m == 1) {

            cout << "invalid" << endl;
            continue;
        }

        if(check() and DFS(sx,sy)) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }

    return 0;
}
