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

bool vis[ 510 ][ 510 ];
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

int n,m;
string s[ 510 ];
bool f,flg;

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
bool add(int x,int y){

    for(int i = 0; i < 4; i++){

        int a = x + X[ i ];
        int b = y + Y[ i ];

        if(check(a,b)){

            if(s[ a ][ b ] == 'W') return false;
            else if(s[ a ][ b ] == '.') s[ a ][ b ] = 'D';
        }
    }
    return true;
}
void DFS(int x,int y){

    if(vis[ x ][ y ]) return;

    vis[ x ][ y ] = true;

    if(s[ x ][ y ] == 'S') f = add(x,y);

    if( !f ) return;

    for(int i = 0; i < 4; i++){

        if( !f ) return;

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        if(check(xx,yy)) DFS(xx,yy);
    }
}

void dfs(int x,int y){

    if(s[ x ][ y ] == 'W') flg = true;

    if(vis[ x ][ y ] ) return;

    vis[ x ][ y ] = true;

    for(int i = 0; i < 4; i++){

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        if(check(xx,yy)) dfs(xx,yy);
    }
}
int main(){

    file();

    f = true;
    flg = false;

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> s[ i ];
//    for(int i = 0; i < n; i++)cout << s[ i ] << endl;
//    cout << endl;

    memset(vis,false,sizeof vis);
    dfs(0,0);

    if( flg ){

        memset(vis,false,sizeof vis);

        DFS(0,0);

        if( !f ) cout << "No\n";
        else {

            cout << "Yes\n";
            for(int i = 0; i < n; i++) cout << s[ i ] << endl;
        }
    }
    else {

        cout << "Yes\n";
        for(int i = 0; i < n; i++) cout << s[ i ] << endl;
    }

    return 0;
}
