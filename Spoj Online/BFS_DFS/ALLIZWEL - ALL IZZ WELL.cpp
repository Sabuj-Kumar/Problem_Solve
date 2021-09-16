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

string s = "ALLIZZWELL";
string grid[ 110 ];
int n,m,sz;
bool flag,ok,vis[ 110 ][ 110 ] = {false};

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
bool DFS(int x,int y,int idx){

    if(idx == sz - 1 and s[ idx ] == grid[ x ][ y ]) return true;

    if(s[ idx ] != grid[ x ][ y ]) return false;

    for(int i = 0; i < 8; i++){

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        bool flag = false;

        if(check(xx,yy) and !vis[ xx ][ yy ]){

            vis[ xx ][ yy ] = true;
            flag = DFS(xx,yy,idx + 1);
            vis[ xx ][ yy ] = false;

            if(flag) return true;
        }
    }
    return false;
}
int main(){

    sz = s.size();

    file();

    int t;

    cin >> t;

    Case( t ){

        memset(vis,false,sizeof vis);

        cin >> n >> m;

        //cout << n << " " << m << endl;
        for(int i = 0; i < n; i++) cin >> grid[ i ];
//        for(int i = 0; i < n; i++) cout << grid[ i ] << endl;
//        cout << endl;

        ok = false;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

               ok = DFS(i,j,0);
               if(ok) break;
            }

            if(ok) break;
        }

        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
