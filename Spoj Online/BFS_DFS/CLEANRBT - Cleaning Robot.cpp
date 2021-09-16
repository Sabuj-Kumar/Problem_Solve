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
#define sl( n ) scanf("%d",&n)
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
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
vector< pii > v;
string s[ N  ];
int vis[ 12 ][ N ][ N ];
int dp[ 1 << 16 ][ 22 ];
int n,m,ln,sz;

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
void BFS(int idx,int a,int b){

    memset(vis[ idx ],-1,sizeof vis[ idx ]);

    queue< pii > q;

    q.push({a,b});

    vis[ idx ][ a ][ b ] = 0;

    while(!q.empty()){

        pii p = q.front();

        q.pop();

        for(int i = 0; i < 4; i++){

            int x = p.ft + X[ i ];
            int y = p.sd + Y[ i ];

            if(check(x,y) and s[ x ][ y ] != 'x' and vis[ idx ][ x ][ y ] == -1){

                vis[ idx ][ x ][ y ] = vis[ idx ][ p.ft ][ p.sd ] + 1;

                q.push({x,y});
            }
        }
    }
}

int Bitmask(int mask,int idx){

    if(mask == ln) return 0;

    if(dp[ mask ][ idx ] != -1) return dp[ mask ][ idx ];

    int ans = 1e9;

    for(int i = 0; i < sz; i++){

        if(!(mask & (1 << i)))
            ans = min(ans,vis[ idx ][ v[ i ].ft ][ v[ i ].sd ] + Bitmask(mask | (1 << i),i));
    }

    return dp[ mask ][ idx ] = ans;
}
int main(){

    file();

    while(cin >> m >> n and (n + m)){

        v.clear();

        int x,y;

        for(int i = 0; i < n; i++) {

            cin >> s[ i ];

            for(int j = 0; j < m; j++){

                if(s[ i ][ j ] == '*') v.pb({i,j});
                if(s[ i ][ j ] == 'o') x = i,y = j;
            }
        }

        v.insert(v.begin(),{x,y});

        sz = v.size();

        ln = (1 << sz) - 1;

        for(int i = 0; i < sz; i++) BFS(i,v[ i ].ft,v[ i ].sd);

        memset(dp,-1,sizeof dp);

        bool flag = false;

        for(int i = 1; i < sz; i++){

            if(vis[ i ][ v[ 0 ].ft ][ v[ 0 ].sd ] == -1){

                flag = true;
                break;
            }
        }

        if(flag) cout << -1 << endl;
        else cout << Bitmask(0,0) << endl;
    }

    return 0;
}
