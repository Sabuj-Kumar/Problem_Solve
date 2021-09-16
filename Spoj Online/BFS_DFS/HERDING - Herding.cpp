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
#define op ios_base::sycn_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1050;
int n,m;
string s[ N ];
int cnt,ans;
int vis[ N ][ N ];

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
void DFS(int x,int y){

    if(check(x,y)){

        if(vis[ x ][ y ]){

            cnt = vis[ x ][ y ];

            return;
        }

        vis[ x ][ y ] = cnt;

        if(s[ x ][ y ] == 'E') DFS(x,y+1);
        else if(s[ x ][ y ] == 'W') DFS(x,y-1);
        else if(s[ x ][ y ] == 'N') DFS(x-1,y);
        else if(s[ x ][ y ] == 'S') DFS(x + 1,y);

        vis[ x ][ y ] = cnt;
    }
}
int main(){

    file();

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> s[ i ];

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(vis[ i ][ j ] == 0){

                cnt = ans + 1;

                DFS(i,j);

                if(cnt > ans) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
