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
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,m,id;
vector< vector< int > > graph;
vector< int > dis,color;

int BFS(int value){

    int cnt = INT_MAX;

    queue< pii > q;

    q.push({value,0});

    dis[ value ] = 1;

    while(!q.empty()){

        pii u = q.front();

        q.pop();

        for(auto x : graph[ u.ft ]){

            if(dis[ x ] == -1){

                if(color[ x ] == id){

                    cnt = u.sd + 1;

                    return cnt;
                }

                dis[ x ] = 1;

                q.push({x,u.sd + 1});
            }
        }
    }

    return cnt;
}
int main(){

    //file();

    cin >> n >> m;

    vector< vector< int > > v(n + 5);
    vector< int > d(n + 5,-1),c(n + 5);
    swap(graph,v);
    swap(d,dis);
    swap(c,color);

    for(int i = 0; i < m; i++){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
        graph[ b ].pb( a );
    }

    for(int i = 1; i <= n; i++) cin >> color[ i ];

    cin >> id;

    int ans = INT_MAX;

    for(int i = 1; i <= n; i++){

        if(color[ i ] == id){

            int c = BFS( i );

            ans = min(c,ans);
        }
    }

    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
