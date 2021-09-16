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
#define gray 1
#define black 2

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e4 + 100;
int node,edge;
vector< int > graph[ N ];
stack< int > st;
bool vis[ N ],cycle;
int color[ N ];

bool cmp(int a,int b){

    return a > b;
}
void DFS(int n){

    if(vis[ n ]) return;

    vis[ n ] = true;

    color[ n ] = gray;

    for(auto x : graph[ n ]){

        if(vis[ x ] and color[ x ] == gray and color[ n ] == gray) cycle = true;

        else if(!vis[ x ])DFS( x );
    }

    color[ n ] = black;

    st.push( n );
}
int main(){

    file();

    cin >> node >> edge;

    while(edge--){

        int a,b;

        cin >> a >> b;

        graph[ a ].pb( b );
    }

    for(int i = 1; i <= node; i++) sort(graph[ i ].begin(),graph[ i ].end(),cmp);

    bool flag = true;

    for(int i = node; i >= 1; i--)
        if(!vis[ i ])
            DFS( i );

    if(cycle) cout << "Sandro fails." << endl;
    else{

        for(int i = 0; i < node - 1; i++) {

            cout << st.top() << " ";
            st.pop();
        }

        cout << st.top() << endl;
    }

    return 0;
}
