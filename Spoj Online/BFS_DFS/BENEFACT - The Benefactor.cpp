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

const int N = 50010;
vector< vector< pii > > graph;
bool vis[ N ];
int node,res;

void DFS(int parent,int dis){

    if(res < dis){

        res = dis;
        node = parent;
    }

    vis[ parent ] = true;

    for(auto x : graph[ parent ])
        if(!vis[ x.ft ])
            DFS(x.ft,dis + x.sd);

    vis[ parent ] = false;
}

int main(){

    //file();

    int t;

    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector< vector< pii >> v(n + 5);
        swap(graph,v);

        for(int i = 1; i < n; i++){

            int a,b,c;

            cin >> a >> b >> c;
            graph[ a ].pb({b,c});
            graph[ b ].pb({a,c});
        }

        res = 0,node = 0;

        DFS(1,0);

        res = 0;

        DFS(node,0);

        cout << res << endl;
    }
    return 0;
}
