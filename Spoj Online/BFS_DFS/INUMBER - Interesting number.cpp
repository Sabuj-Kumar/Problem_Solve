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

struct digit{

    int idx;
    int sum;
    int mod;
};

const int N = 1e3 + 10;
int vis[ N ][ N ];
digit dp[ N ][ N ];
int ans[ 10005 ];

void BFS(int n){

    memset(vis,0,sizeof vis);

    queue< pii > q;

    q.push({0,0});

    vis[ 0 ][ 0 ] = 1;

    dp[ 0 ][ 0 ].sum = 0;
    dp[ 0 ][ 0 ].mod = 0;

    while( !q.empty() ){

        pii p = q.front();

        q.pop();

        if(p.ft == n and p.sd == 0) break;

        for(int i = 0; i < 10; i++){

            int x = p.ft + i;
            int y = (10 * p.sd + i) % n;

            if(x > n) break;

            if(vis[ x ][ y ] == 0){

                dp[ x ][ y ].idx = i;
                dp[ x ][ y ].sum = p.ft;
                dp[ x ][ y ].mod = p.sd;

                vis[ x ][ y ] = 1;

                q.push({x,y});
            }
        }
    }
}

int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        int n;
        cin >> n;

        if(n < 10){

            cout << n << endl;
            continue;
        }
        BFS( n );

        int x = n;
        int y = 0;
        int idx = 0;

        while(true){

            ans[ idx++ ] = dp[ x ][ y ].idx;
            int a = dp[ x ][ y ].sum;
            int b = dp[ x ][ y ].mod;

            x = a;
            y = b;

            if(x == 0) break;
        }

        for(int i = idx - 1; i >= 0; i--) cout << ans[ i ];
        cout << endl;
    }

    return 0;
}
