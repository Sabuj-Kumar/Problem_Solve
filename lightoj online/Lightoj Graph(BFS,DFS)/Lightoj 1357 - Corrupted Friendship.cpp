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

const int N = 1e5 + 10;
vector< vector< int > > graph;
bool vis[ N ];
ll n,friend_,not_friend;

void DFS(int node){

    if(vis[ node ]) return;

    vis[ node ] = true;

    friend_++;

    for(auto x : graph[ node ]) DFS( x );

    not_friend += (n - friend_);
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        memset(vis,false,sizeof vis);

        cin >> n;

        vector< vector< int > > v(n + 5);
        swap(graph,v);

        for(int i = 1; i < n; i++){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        friend_ = not_friend = 0;

        DFS( 1 );

        printf("Case %d: %lld %lld\n",cs,n-1,not_friend);
    }

    return 0;
}
