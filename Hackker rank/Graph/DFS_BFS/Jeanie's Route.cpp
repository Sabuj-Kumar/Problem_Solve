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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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

const int N = 1e5+10;
int n,k;
int ans,D;
vector< vector< pii > > graph;
int vis[ N ],node[ N ],okay[ N ];

void DFS(int n,int p = 0){

    for(auto x : graph[ n ]){

        if(x.ft != p){

            DFS(x.ft,n);

            okay[ n ] |= okay[ x.ft ];
        }
    }

    okay[ n ] |= vis[ n ];
}

int Diameter(int node,int p = 0){

    pii s = {0,0};

    for(auto x : graph[ node ]){

        if(x.ft != p and okay[ x.ft ]){

            ans += x.sd;

            s.sd = max(s.sd,Diameter(x.ft,node)+x.sd);

            if(s.ft < s.sd) swap(s.ft,s.sd);
        }
    }

    D = max(D,s.ft+s.sd);

    return s.ft;
}
int main(){

    file();

    cin >> n >> k;

    vector< vector< pii > > v(n + 5);
    swap(v,graph);

    for(int i = 1; i <= k; i++) {

        cin >> node[ i ];

        vis[ node[ i ] ] = 1;
    }

    for(int i = 1; i < n; i++){

        int a,b,c;

        cin >> a >> b >> c;

        graph[ a ].pb({b,c});
        graph[ b ].pb({a,c});
    }

    DFS(node[ 1 ]);

    Diameter(node[ 1 ]);

    cout << 2 * ans - D << endl;

    return 0;
}
