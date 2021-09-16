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

const int N = 100;

int grid[ N + 5 ];
bool vis[ N + 5 ];

void init(){

    memset(grid,-1,sizeof grid);
    memset(vis,false,sizeof vis);
}

int BFS(int node){

    queue< pii > q;

    vis[ node ] = true;

    q.push({node,0});

    pii v;

    while(!q.empty()){

        v = q.front();

        q.pop();

        if(v.ft == N) return v.sd;

        for(int i = v.ft + 1; i <=(v.ft + 6) and i <= N; i++){

            if(!vis[ i ]){

                vis[ i ] = true;
                pii a;

                a.sd = (v.sd + 1);

                if(grid[ i ] != -1) a.ft = grid[ i ];
                else a.ft = i;

                q.push(a);
            }
        }
    }

    return -1;
}
int main(){

    //file();

    int t;

    cin >> t;

    while( t-- ){

        init();
        int n,m;

        cin >> n;

        for(int i = 0; i < n; i++){

            int a,b;

            cin >> a >> b;

            grid[ a ] = b;
        }

        cin >> m;

        for(int i = 0; i < m; i++){

            int a,b;

            cin >> a >> b;

            grid[ a ] = b;
        }

        int ans = BFS( 1 );

        cout << ans << endl;
    }
    return 0;
}
