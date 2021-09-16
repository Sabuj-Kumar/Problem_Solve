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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,1,-1,-1,1};
int array_[ 11 ][ 11 ];
int vis[ 11 ][ 11 ];
int n,m,mx,cnt;

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}

void DFS(int x,int y){

    if(vis[ x ][ y ] != 0) return;

    vis[ x ][ y ] = cnt++;

    mx = max(mx,cnt);

    for(int i = 0; i < 8; i++){

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        if(check(xx,yy) and array_[ xx ][ yy ]) DFS(xx,yy);
    }
}

int main(){

    file();

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
         cin >> array_[ i ][ j ];

    mx = -1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(vis[ i ][ j ] == 0 and array_[ i ][ j ] == 1)
            { cnt = 1; DFS(i,j); }

    cout << mx - 1 << endl;

    return 0;
}
