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
#define in_ freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in_;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e5 + 10;
vector< vector< int > > graph;
int in[ N ],out[ N ];

void DFS(int pa,int node){

    in[ node ] = 0;

    int mx1 = 0,mx2 = 0;

    for(auto x : graph[ node ]){

        if(x != pa){

            DFS(node,x);

            out[ node ] = max(out[ node ],out[ x ]);

            int v = in[ x ] + 1;

            if(v > mx1){

                mx2 = mx1;
                mx1 = v;
            }
            else if(v > mx2) mx2 = v;
        }
    }

    out[ node ] = max(out[ node ],mx1 + mx2);
    in[ node ] = mx1;
}

int main(){

    file();

    int n,root;

    cin >> n;
    vector< vector< int > > v( n + 3 );
    swap(graph,v);

    for(int i = 1; i < n; i++){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
        graph[ b ].pb( a );
    }

    int s;

    cin >> s;

    DFS(0,s);

    int q;

    cin >> q;

    while(q--){

        int s;

        cin >> s;

        cout << out[ s ] << endl;
    }

    return 0;
}
