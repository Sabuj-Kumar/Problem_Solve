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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

string s[ 22 ];
int sz,len,n,m;
vector< pii > v;
int vis[ 18 ][ 25 ][ 25 ];
int dp[ 22 ][ 1 << 18 ];

bool check(int a,int b){

    return a >=0 and a < n and b >= 0 and b < m;
}
void bfs(int idx,int i,int j){

    memset(vis[ idx ],-1,sizeof vis[ idx ]);
    queue< pii > q;

    vis[ idx ][ i ][ j ] = 0;

    q.push({i,j});

    while( !q.empty() ){

        pii u = q.front();

        q.pop();

        for(int i = 0; i < 8; i++){

            int a = u.ft + X[ i ];
            int b = u.sd + Y[ i ];

            if(check(a,b) and vis[ idx ][ a ][ b ] == -1){

                vis[ idx ][ a ][ b ] = vis[ idx ][ u.ft ][ u.sd ] + 1;
                q.push({a,b});
            }
        }
    }
}

int bit_mask(int idx,int mask){

    if(mask == len) return vis[ idx ][ v[ 0 ].ft ][ v[ 0 ].sd ];

    if(dp[ idx ][ mask ] != -1) return dp[ idx ][ mask ];

    int ans = 1e9;

    for(int i = 0; i < sz; i++)
        if( !(mask & (1 << i) ) )
            ans = min(ans,vis[ idx ][ v[ i ].ft ][ v[ i ].sd ] + bit_mask(i,mask | (1 << i)));

    return dp[ idx ][ mask ] = ans;
}
int main(){

    //file();

    int t = I();

    Case( t ){

        memset(dp,-1,sizeof dp);
        v.clear();

        int x,y;

        n = I();
        m = I();

        for(int i = 0; i < n; i++) cin >> s[ i ];

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(s[ i ][ j ] == 'x') x = i,y = j;
                if(s[ i ][ j ] == 'g') v.pb({i,j});
            }
        }

        v.insert(v.begin(),{x,y});

        for(int i = 0; i < v.size(); i++) bfs(i,v[ i ].ft,v[ i ].sd);

        sz = v.size();
        len = (1 << sz) - 1;

        int ans = bit_mask( 0,0 );

        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
