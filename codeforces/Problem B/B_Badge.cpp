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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e3 + 10;

vector<int> graph[ N ];
bool vis[ N ];
int idx,out[ N ];

void DFS(int node,int idx){

    if(out[ idx ] != 0) return;

    if(vis[ node ]){

        out[ idx ] = node;

        return;
    }

    vis[ node ] = true;

    for(auto x : graph[ node ]) DFS( x,idx );
}
int main(){

    //file();

    int n;
    cin >> n;
    idx = 0;

    for(int i = 1; i <= n; i++){

        int a;

        cin >> a;

        graph[ i ].pb( a );
    }

    for(int i = 1; i <= n; i++){

        memset(vis,false,sizeof vis);

        DFS(i,i);
    }

    for(int i = 1; i <= n; i++) cout << out[ i ] << " ";

    cout << endl;

    return 0;
}
