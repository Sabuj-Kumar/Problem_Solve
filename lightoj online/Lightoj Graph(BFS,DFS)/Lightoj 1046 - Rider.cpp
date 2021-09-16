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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

string s[ 12 ];
int n,m;
int vis[ 110 ][ 12 ][ 12 ];

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}

void bfs(int idx,int i,int j){

    queue< pii > q;
    vis[ idx ][ i ][ j ] = 0;

    q.push({i,j});

    while(!q.empty()){

        pii u = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){

            int x = u.ft + hx[ i ];
            int y = u.sd + hy[ i ];

            if(check(x,y) and vis[ idx ][ x ][ y ] == -1){

                vis[ idx ][ x ][ y ] = vis[ idx ][ u.ft ][ u.sd ] + 1;
                q.push({x,y});
            }
        }
    }
}

int main(){

    file();

    int t = I();

    Case( t ) {

        memset(vis,-1,sizeof vis);

        n = I();
        m = I();
        int num = 0;
        int v[ 110 ];

        for(int i = 0; i < n; i++) cin >> s[ i ];

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(s[ i ][ j ] != '.'){

                    v[ num ] = s[ i ][ j ] - '0';
                    bfs(num,i,j);
                    num++;
                }
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                int cnt = 0,cost = 0;

                for(int k = 0; k < num; k++){

                    if(vis[ k ][ i ][ j ] != -1) {

                        int weight = 0;

                        if(vis[ k ][ i ][ j ]) weight = (vis[ k ][ i ][ j ] - 1) / v[ k ] + 1;

                        cost += weight;
                        cnt++;
                    }
                }

                if(cnt == num) ans = min(cost,ans);
            }
        }

        cout << "Case " << cs << ": ";

        if(ans == INT_MAX) ans = -1;

        cout << ans << endl;

    }
    return 0;
}
